# QTWordShuffle
Created for COP 3003, Programming II FGCU 2023.

A version of my Word Shuffle game for Windows Desktop made with Qt Creator with C++ and CMake.



Goal:  
A word game for windows which shows the definition of a word and scrambled letters. 
The objective is to figure out the word and rearrange the letters into the correct order by dragging them into the appropriate positions.
 
Current Status:  
Letters and their targets are properly displaying. But the system does not keep track of which letter is where and the letters do not lock
into place. This functionality will be added soon.

As of last update:  
A new class was created called TargetLabels which will mostly just be a QLabel but will have a "QPoint center" property which will store
the center of the imagetarget for use later. 

Next Steps:  
Implement locking functionality. 
If a letter is within a certain distance (to be determined) of a target it will center itself within the target.

## Process

This is built with Qt Creator, CMake, and C++

## Purpose
This was created for a C++ programming class. 
Since I built a version of this application for Android in Java, this was an opportunity for me to learn
about the language differences and see which aspects of development carry over and which need to be done differently.

Since this a GUI with visual elements that need to be updated and destroyed I figured it would give me the opportunity to 
work with many of the aspects that differentiate C++ from Java, specifically in terms of object construction and memory management.

## Contributors

Aleksandr Strizhevskiy, astrizhevskiy@eagle.fgcu.edu
