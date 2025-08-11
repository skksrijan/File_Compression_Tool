# File_Compression_Tool


COMPANY: CODTECH IT SOLUTIONS

NAME: SRIJAN KUMAR

INTERN ID: CT06DH541

DOMAIN: C++

DURATION: 6 WEEKS

MENTOR: NEELA SANTOSH

DESCRIPTION:
Overview
This project is a high-performance file management utility designed to compress and decompress files using multithreading for speed optimization. It is implemented entirely in C++, leveraging modern C++17 features and libraries such as std::thread, std::atomic, and zlib for compression algorithms. The primary goal is to demonstrate measurable performance gains by parallelizing the compression process, making it ideal for large files or batch file operations.

Objective
The objective is to design a tool that:

Reduces file size to save storage and improve data transfer efficiency.

Utilizes multiple CPU cores for parallel chunk-based compression, significantly reducing execution time compared to single-threaded methods.

Provides a robust and portable implementation for integration into larger file management systems.

Technical Approach
The compression process is implemented using a divide-and-conquer strategy:

The input file is read into memory and divided into fixed-size chunks.

Each chunk is processed by a separate thread, which compresses the data independently using zlib.

A thread-safe counter (std::atomic<size_t>) ensures no two threads process the same chunk.

The compressed chunks are written sequentially with headers containing metadata (original size and compressed size) for decompression.

The decompression process reverses this:

The compressed file is read.

Output:
![img]()

Chunk headers are parsed to determine each block’s original size.

Each chunk is decompressed in parallel and reassembled in the original order.
