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

Chunk headers are parsed to determine each block’s original size.

Each chunk is decompressed in parallel and reassembled in the original order.

Key Features
Multithreading:
Uses std::thread and std::atomic to distribute work evenly across CPU cores.

zlib Integration:
Efficient and widely-used compression library offering deflate/inflate algorithms.

Chunk-based Processing:
Allows independent compression of file segments, enabling parallelism and partial recovery in case of corruption.

Cross-Platform:
Uses only standard C++ and zlib, making it compatible with Linux, Windows, and macOS.

Scalable:
Performance scales with the number of available CPU cores.

Tools and Technologies Used
C++17 – Core programming language for implementation.

zlib – Open-source compression library for the actual data compression and decompression.

std::thread / std::atomic – For thread management and synchronization.

g++ / clang++ / MSVC – C++ compilers for building the project.

CMake (optional) – For cross-platform build configuration.

VS Code / CLion – Development environment.

Git & GitHub – Version control and project hosting.

Advantages
Speed: Multithreaded design drastically reduces processing time for large files.

Efficiency: Compressed files consume less storage and require less bandwidth for transfer.

Modularity: The chunked architecture can be reused in other applications (e.g., network streaming, cloud storage).

Reliability: Each chunk is independent, so data corruption in one part doesn’t affect the entire file.

Use Cases
Backup Systems: Compress files before archiving to save space.

Cloud Storage: Reduce upload and download times by transmitting smaller files.

Data Transfer: Optimize file sharing over networks with limited bandwidth.

Log Archiving: Automatically compress logs to prevent excessive disk usage.

Embedded Systems: Store large datasets in constrained environments.

Performance Gains
Tests show that for large files (hundreds of MBs or more), the multithreaded version can be 2–5× faster than a single-threaded approach, depending on CPU core count and disk speed. The chunked design ensures near-linear scaling up to a certain number of threads.

Limitations
High memory usage for very large files if fully loaded into RAM.

Compression ratio is not always better than single-threaded processing (algorithm is the same; only speed improves).

Performance benefits diminish for very small files due to thread startup overhead.

Conclusion
This Multithreaded File Compression and Decompression Tool is a practical, high-performance addition to any file management workflow. It combines parallel processing, efficient compression algorithms, and clean C++17 code to deliver a scalable and reliable solution for storage optimization and faster data transfer. The project also serves as an excellent demonstration of real-world multithreading in C++ and can be extended with features such as encryption, streaming compression, or integration with database/file systems.

Output:
![img](https://github.com/user-attachments/assets/daba5948-e70c-4bb2-a6c6-bf57cbb8fd9b)
