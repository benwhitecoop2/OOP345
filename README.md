# OOP345

Virtualized assembly line written in C++ for OOP345. This project is exclusively for demonstration to a potential employer.

AssemblyLine.cpp -  Execution file for project. Contains main().
LineManager.cpp / LineManager.h - Defenition and declaration for LineManager class, creates the virtual assembly line from two vectors and moves objects through while performing operations
Task.cpp / Task.h - Defenition and declaration for Task class, manages a dynamic array of CustomerOrders for implementation by LineManager class
CustomerOrder.h / CustomerOrder.cpp - Defenition and declaration for CustomerOrder class, manages a list of items in an order
Item.cpp / Item.h - Defenition and declaration for Item class, specification for each individual item on the assembly line. Used by CustomerOrder class and then Task class
Utilities.cpp / Utilities.h - Defenition and declaration for Utilities class, provides functions which set up each Item automatically. Enables the assembly line to automatically read data in from files
