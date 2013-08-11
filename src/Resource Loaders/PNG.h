#pragma once
#include <string>
#include <vector>

// http://www.libpng.org/pub/png/spec/1.2/PNG-Chunks.html PNG Format Reference

// A struct to hold all chunk data.
struct chunk {
	chunk();
	chunk(const chunk &other);
	~chunk();
	unsigned int size;
	unsigned char type[4];
	unsigned char* data;
	unsigned char CRC[4];
};

class PNGLoader {
public:
	PNGLoader() {}
	~PNGLoader() {}

	/**
	 * \brief Loads and chunks a PNG file.
	 *
	 * Load a PNG file with the given filename. The file signature is checked and then the remainder of the file is chunked and stored.
	 * \param[in] std::string fname The name of the PNG file to load.
	 * \returns   bool true on successful loading and chunking.
	 */
	bool Load(std::string fname);
	/**
	 * \brief Checks the PNG signature.
	 *
	 * Given an input file stream, the first 8 bytes are checked to verify they match the PNG signature.
	 * \param[in] std::ifstream & file The input file stream to check the signature. The file pointer is reset during this call, and is not restored on return.
	 * \returns   bool true on a good match.
	 */
	bool CheckSignature(std::ifstream& file);

	/**
	 * \brief Read the next chunk in a PNG file.
	 *
	 * The next chunk is read and parsed out. The internal file pointer must be at the beginning of the next chunk.
	 * \param[in] std::ifstream & file The input file stream to read the next chunk from. The file pointer is changed to the next position after the chunk.
	 * \returns   chunk The newly created chunk.
	 */
	chunk ReadChunk(std::ifstream& file);

	void ParseChunks();

private:
	char* data;
	std::vector<chunk> chunks;
};