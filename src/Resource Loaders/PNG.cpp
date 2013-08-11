#include "PNG.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

chunk::chunk() : size(0), data(nullptr) { }

chunk::chunk(const chunk &other) {
	this->size = other.size;
	this->data = new unsigned char[this->.size];
	memcpy(this->data, other.data, this->.size);
	memcpy(this->type, other.type, 4);
	memcpy(this->CRC, other.CRC, 4);
}

chunk::~chunk() {
	delete this->data;
}

bool PNGLoader::Load(std::string fname) {
	std::ifstream file;
	file.open(fname, std::ios_base::in | std::ios_base::binary);

	cout << "Loading file " << fname << endl;

	// Verify the PNG signature.
	if (!CheckSignature(file)) {
		return false;
	}

	// Loop through and read each chunk.
	while (!file.eof()) {
		this->chunks.push_back(ReadChunk(file));
		file.peek();
	}

	return true;
}

bool PNGLoader::CheckSignature(std::ifstream& file){
	file.seekg(0);
	// Read in the signature which is 8 bytes long
	char sig[8];
	file.read(sig, 8);

	static const unsigned char PNG_SIGNATURE[] = { 0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A };
	// Compare the read signature to the constant.
	for (unsigned int i = 0; i < 8; i++) {
		// The comparison needs to be between unsigned characters so we need to do a cast.
		if (static_cast<unsigned char>(sig[i]) != PNG_SIGNATURE[i]) {
			return false;
		}
	}
	return true;
}

chunk PNGLoader::ReadChunk(std::ifstream& file) {
	chunk c;
	unsigned char chunkHDR[8];

	// Read the header.
	file.read(reinterpret_cast<char*>(&chunkHDR), 8);

	// Now we need to split the chunkHDR into size and type.
	// To get the size we need to add each byte to our int and shift it over.
	c.size += chunkHDR[0]; c.size = c.size << 8;
	c.size += chunkHDR[1]; c.size = c.size << 8;
	c.size += chunkHDR[2]; c.size = c.size << 8;
	c.size += chunkHDR[3];

	c.type[0] = chunkHDR[4]; c.type[1] = chunkHDR[5]; c.type[2] = chunkHDR[6]; c.type[3] = chunkHDR[7];

	// Read the data.
	c.data = new unsigned char[c.size];
	file.read(reinterpret_cast<char*>(c.data), c.size);

	// Read the CRC
	file.read(reinterpret_cast<char*>(&c.CRC), 4);

	return c;
}

void PNGLoader::ParseChunks() {
	for (auto itr = this->chunks.begin(); itr != this->chunks.end(); ++itr) {

	}
}
