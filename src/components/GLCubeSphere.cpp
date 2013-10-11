#include <vector>
#include <algorithm>
#include <limits>

//#include "SDL/SDL.h"
//#include "SDL/SDL_image.h"

#include "SOIL/SOIL.h"

#include "GLCubeSphere.h"

const float epsilon = 0.0001f;

// For std::find
namespace Sigma {
	bool operator ==(const Vertex &lhs, const Vertex &rhs) { return ((abs(rhs.x - lhs.x) < epsilon) &&
																	 (abs(rhs.y - lhs.y) < epsilon) &&
																	 (abs(rhs.z - lhs.z) < epsilon)); }
}

GLCubeSphere::GLCubeSphere( const int entityID /*= 0*/ ) : Sigma::IGLComponent(entityID) {
	this->drawMode = GL_TRIANGLES;
	this->VertBufIndex = 0;
	this->ColorBufIndex = 1;
	this->ElemBufIndex = 2;
}

GLCubeSphere::~GLCubeSphere() {
	glDeleteTextures(1, &this->_cubeMap);
}

void GLCubeSphere::InitializeBuffers() {
	srand(this->GetEntityID());

	// Create the verts to begin refining at.
	float t = 1.0f;
	glm::vec3 coordPair(t, t, t);

	this->verts.push_back(Sigma::Vertex(-coordPair.x, -coordPair.y, coordPair.z));
	this->verts.push_back(Sigma::Vertex(coordPair.x, -coordPair.y, coordPair.z));
	this->verts.push_back(Sigma::Vertex(coordPair.x, coordPair.y, coordPair.z));
	this->verts.push_back(Sigma::Vertex(-coordPair.x, coordPair.y, coordPair.z));
	this->verts.push_back(Sigma::Vertex(-coordPair.x, -coordPair.y, -coordPair.z));
	this->verts.push_back(Sigma::Vertex(coordPair.x, -coordPair.y, -coordPair.z));
	this->verts.push_back(Sigma::Vertex(coordPair.x, coordPair.y, -coordPair.z));
	this->verts.push_back(Sigma::Vertex(-coordPair.x, coordPair.y, -coordPair.z));

	// front
	this->faces.push_back(Sigma::Face(0,1,2));
	this->faces.push_back(Sigma::Face(2,3,0));
	// top
    this->faces.push_back(Sigma::Face(3,2,6));
    this->faces.push_back(Sigma::Face(6, 7, 3));
    // back
    this->faces.push_back(Sigma::Face(7, 6, 5));
    this->faces.push_back(Sigma::Face(5, 4, 7));
    // bottom
    this->faces.push_back(Sigma::Face(4, 5, 1));
    this->faces.push_back(Sigma::Face(1, 0, 4));
    // left
    this->faces.push_back(Sigma::Face(4, 0, 3));
    this->faces.push_back(Sigma::Face(3, 7, 4));
    // right
    this->faces.push_back(Sigma::Face(1, 5, 6));
    this->faces.push_back(Sigma::Face(6, 2, 1));

	std::cout << "Subdividing cube sphere..." << std::endl;
	this->SubDivide(this->_subdivisionLevels);

	std::cout << "Loading cube sphere data..." << std::endl;
	glGenVertexArrays(1, &this->vao); // Generate the VAO
	glBindVertexArray(this->vao); // Bind the VAO

	glGenBuffers(1, &this->buffers[this->VertBufIndex]); 	// Generate the vertex buffer.
	glBindBuffer(GL_ARRAY_BUFFER, this->buffers[this->VertBufIndex]); // Bind the vertex buffer.
	glBufferData(GL_ARRAY_BUFFER, sizeof(Sigma::Vertex) * this->verts.size(), &this->verts.front(), GL_STATIC_DRAW); // Stores the verts in the vertex buffer.
	GLint posLocation = glGetAttribLocation(this->_shader.GetProgram(), "in_Position"); // Find the location in the shader where the vertex buffer data will be placed.
	glVertexAttribPointer(posLocation, 3, GL_FLOAT, GL_FALSE, 0, 0); // Tell the VAO the vertex data will be stored at the location we just found.
	glEnableVertexAttribArray(posLocation); // Enable the VAO line for vertex data.

	glGenBuffers(1, &this->buffers[this->ElemBufIndex]); // Generate the element buffer.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->buffers[this->ElemBufIndex]); // Bind the element buffer.
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Sigma::Face) * this->faces.size(), &this->faces.front(), GL_STATIC_DRAW); // Store the faces in the element buffer.

	glBindVertexArray(0); // Reset the buffer binding because we are good programmers.
}

void GLCubeSphere::LoadTexture(std::string texture_name) {
	// albedo map
	std::cout << "Loading cube map" << std::endl;

	// First try dds file
	char filename[100];
	char filenames[6][100];

	sprintf(filename, "%s.dds", texture_name.c_str());

	this->_cubeMap = SOIL_load_OGL_single_cubemap(filename, SOIL_DDS_CUBEMAP_FACE_ORDER, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_DDS_LOAD_DIRECT);
	
	// if that didn't work, load individual files
	if(this->_cubeMap == 0) {
		// There are always six files
		for(int i=0; i < 6; i++) {
			sprintf(filenames[i], "%s%d.jpg", texture_name.c_str(), i+1);
		}

		this->_cubeMap = SOIL_load_OGL_cubemap(filenames[0], filenames[1], filenames[2], filenames[3], filenames[4], filenames[5], SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

		if( 0 == this->_cubeMap ) {
			std::cerr << "SOIL loading error: " << texture_name.c_str() << " - " << SOIL_last_result() << std::endl;
		}
	}

	std::cout << "Loading cube normal map" << std::endl;

	// First try dds file
	sprintf(filename, "%s_nm.dds", texture_name.c_str());

	this->_cubeNormalMap = SOIL_load_OGL_single_cubemap(filename, SOIL_DDS_CUBEMAP_FACE_ORDER, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_DDS_LOAD_DIRECT);
	
	if(this->_cubeNormalMap==0) {
		// if that didn't work, load individual files
		// There are always six files
		for(int i=0; i < 6; i++) {
			sprintf(filenames[i], "%s_nm%d.jpg", texture_name.c_str(), i+1);
		}

		this->_cubeNormalMap = SOIL_load_OGL_cubemap(filenames[0], filenames[1], filenames[2], filenames[3], filenames[4], filenames[5], SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

		if( 0 == this->_cubeNormalMap ) {
			// It's ok not to have a normal map
			std::cerr << "SOIL loading error: " << texture_name.c_str() << "_nm - " << SOIL_last_result() << std::endl;
		}
	}
}

void GLCubeSphere::SubDivide(int levels) {
	std::vector<Sigma::Face> newFaces;

	Sigma::Vertex v1(0, 0, 0), v2(0, 0, 0), newVert(0, 0, 0);
	Sigma::Face newFace(0, 0, 0);

	short i1, i2, i3;

	// Iterate over each face and subdivide it
	for(std::vector<Sigma::Face>::iterator i = this->faces.begin(); i != this->faces.end(); ++i) {

		// Split each edge
		v1 = this->verts[(*i).v1];
		v2 = this->verts[(*i).v2];

		newVert.x = (v1.x + v2.x)/2.0f;
		newVert.y = (v1.y + v2.y)/2.0f;
		newVert.z = (v1.z + v2.z)/2.0f;

		// See if vertex already exists
		std::vector<Sigma::Vertex>::iterator existingVert = std::find(this->verts.begin(), this->verts.end(), newVert);
		if(existingVert==this->verts.end()) {
			i1 = verts.size();
			this->verts.push_back(newVert);
		}
		else {
			i1 = std::distance(this->verts.begin(), existingVert);
		}

		// Second edge
		v1 = this->verts[(*i).v1];
		v2 = this->verts[(*i).v3];

		newVert.x = (v1.x + v2.x)/2.0f;
		newVert.y = (v1.y + v2.y)/2.0f;
		newVert.z = (v1.z + v2.z)/2.0f;

		existingVert = std::find(this->verts.begin(), this->verts.end(), newVert);
		if(existingVert==this->verts.end()) {
			i2 = this->verts.size();
			this->verts.push_back(newVert);
		}
		else {
			i2 = std::distance(this->verts.begin(), existingVert);
		}

		// third edge
		v1 = this->verts[(*i).v2];
		v2 = this->verts[(*i).v3];

		newVert.x = (v1.x + v2.x)/2.0f;
		newVert.y = (v1.y + v2.y)/2.0f;
		newVert.z = (v1.z + v2.z)/2.0f;

		existingVert = std::find(this->verts.begin(), this->verts.end(), newVert);
		if(existingVert==verts.end()) {
			i3 = this->verts.size();
			this->verts.push_back(newVert);
		}
		else {
			i3 = std::distance(this->verts.begin(), existingVert);
		}

		// Create 4 new faces
		newFace.v1 = (*i).v1;
		newFace.v2 = i1;
		newFace.v3 = i2;
		newFaces.push_back(newFace);

		newFace.v1 = i1;
		newFace.v2 = (*i).v2;
		newFace.v3 = i3;
		newFaces.push_back(newFace);

		newFace.v1 = i3;
		newFace.v2 = i2;
		newFace.v3 = i1;
		newFaces.push_back(newFace);

		newFace.v1 = i2;
		newFace.v2 = i3;
		newFace.v3 = (*i).v3;
		newFaces.push_back(newFace);
	}

	this->faces = newFaces;

	if(levels > 1) {
		this->SubDivide(levels-1);
	}
}

void GLCubeSphere::LoadShader(std::string shader_name) {
	char vertex_shader[100], fragment_shader[100];

	sprintf(vertex_shader, "shaders/%s.vert", shader_name.c_str());
	sprintf(fragment_shader, "shaders/%s.frag", shader_name.c_str());

	this->_shader.LoadFromFile(GL_VERTEX_SHADER, vertex_shader);
	this->_shader.LoadFromFile(GL_FRAGMENT_SHADER, fragment_shader);
	this->_shader.CreateAndLinkProgram();
}

void GLCubeSphere::Render(glm::mediump_float *view, glm::mediump_float *proj) {
	this->_shader.Use();

	// Hack to fix the skybox to the camera
	// Will ultimately use scene graph to accomplish this
	if(this->fix_to_camera) {
		glm::mediump_float *view_ptr = view;
		glm::mat4 view_matrix;

		for(int i=0; i < 4; i++) {
			for(int j=0; j < 4; j++) {
				view_matrix[i][j] = (*view_ptr++);
			}
		}

		// Extract position from view matrix
		glm::mat3 rotMat(view_matrix);
		glm::vec3 d(view_matrix[3]);
		glm::vec3 position = -d * rotMat;
		this->Transform()->TranslateTo(position);
	}

	//this->Transform()->Rotate(0.0f,this->rotation_speed,0.0f);

	glm::mat4 modelMatrix = this->Transform()->GetMatrix();

	glUniform1i(glGetUniformLocation(this->_shader.GetProgram(), "cubeMap"), GL_TEXTURE0);
	glUniform1i(glGetUniformLocation(this->_shader.GetProgram(), "cubeNormMap"), GL_TEXTURE0+1);

	glUniformMatrix4fv(glGetUniformLocation(this->_shader.GetProgram(), "in_Model"), 1, GL_FALSE, &modelMatrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(this->_shader.GetProgram(), "in_View"), 1, GL_FALSE, view);
	glUniformMatrix4fv(glGetUniformLocation(this->_shader.GetProgram(), "in_Proj"), 1, GL_FALSE, proj);

	glBindVertexArray(this->Vao());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->GetBuffer(this->ElemBufIndex));

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, this->_cubeMap);

	glActiveTexture(GL_TEXTURE0+1);
	glBindTexture(GL_TEXTURE_CUBE_MAP, this->_cubeNormalMap);

	glCullFace(this->cull_face);
	glDepthFunc(GL_LEQUAL);

	for (int i = 0, cur = this->MeshGroup_ElementCount(0), prev = 0; cur != 0; prev = cur, cur = this->MeshGroup_ElementCount(++i)) {
		glDrawElements(this->DrawMode(), cur, GL_UNSIGNED_SHORT, (void*)prev);
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	glCullFace(GL_BACK);
	glDepthFunc(GL_LESS);

	this->_shader.UnUse();
}
