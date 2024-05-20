README
======

RAID Mapping Program
====================

Overview
--------
This project involves implementing a program that maps the location of sectors in a RAID device into the sectors of the hard disks that compose it. The program reads input from the standard input and prints the result to the standard output.

Task Description
----------------
Given a scenario composed of a RAID level T ("0", "1", "01", "10", "4", or "5"), the number of hard disks N, the size of the chunks C (in sectors), the number of sectors per disk S, and the number of queries Q, the program must specify which hard disk and stripe contain the queried sector. Additionally, for RAID levels 1, 01, and 10, the program must indicate which other disk has a copy of the queried sector, and for RAID levels 4 and 5, it must specify the hard disk containing the parity affected by the queried sector.

Input Format
------------
The input consists of the following:
1. The first line contains five items in this order: T, N, C, S, and Q.
2. The next Q lines each contain a single queried sector number.

Output Format
-------------
For each query, the program prints one line containing two or three numbers:
1. The hard disk number ([0,N-1]) containing the queried sector.
2. The stripe number ([0,S-1]) containing the queried sector.
3. For RAID levels 1, 01, and 10, the hard disk number ([0,N-1]) containing the second copy of the queried sector. For RAID levels 4 and 5, the hard disk number ([0,N-1]) containing the parity affected by the queried sector.

Test Case Restrictions
-----------------------
- Hard disks are numbered from 0 to N-1. N is in the range [2,16].
- N is always 2 for RAID level 1.
- N is always an even number greater than 3 for RAID levels 01 and 10.
- N is always greater than 2 for RAID levels 4 and 5.
- Chunk size C is a number in the range [1,16] for RAID level 0.
- C is always 1 for other RAID levels.
- Stripes and disk sectors are numbered from 0 to S-1.
- The number of sectors per disk S is greater than 1 and is always a multiple of C.
- S is in the order of billions.
- The number of queries Q is in the order of millions.

Building and Running
---------------------
1. Compile the program:
    ```
    make
    ```
2. Run the compiled program:
    ```
    make run
    ```
