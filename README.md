# Prog2_Assignment
An OOP project built on Java and C++.

# Implemented By
1. Siddharth Kothari - roll no IMT2021019 
2. Sankalp Kothari - roll no IMT2021028 
3. M Srinivasan - roll no IMT2021058

# Project description
Kindly go through the attached pdf to view the project details and get an idea about the organisatin of the files, and what the project intends to achieve. 

# Instructions to run the program
1. To simulate the working of multiple portals, you can open different terminals, with different portalids in the portalmain.cpp file.
2. PlatformMain.java runs in one terminal, while the other terminals run various portals, each with different portal ids.
3. First of all, navigate to the directory containing all the files (ecomm v1.1)
4. To run the PortalMain.cpp file (with all dependencies) run the commands
```   
g++ PortalMain.cpp demo/Portal1.cpp ecomm/Portal.cpp ecomm/Product.cpp
./a.out
```

5. To run the PlatformMain.java, run the commands
```
javac PlatformMain.java
java PlatformMain
```

6. You can now enter commands as described in the pdf, and observe outputs in the terminal and the files "PlatformToPortal.txt" and "PortalToPlatform.txt".