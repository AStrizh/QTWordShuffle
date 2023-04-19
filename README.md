# QTWordShuffle
Created for COP 3003, Programming II FGCU 2023.

A version of my Word Shuffle game for Windows Desktop made with Qt Creator with C++ and CMake.



Goal:  
A word game for windows which shows the definition of a word and scrambled letters. 
The objective is to figure out the word and rearrange the letters into the correct order by dragging them into the appropriate positions.
 
Current Status:  
All major logic and functionality is completed. From here only UI/UX work left. When the word is solved, right now, there is
only a message in the terminal. Will create some UI element that informs user when correct or incorrect. 

As of last update:  
Letters lock in position and track their "correctness". If two letters are moved into the same spot the overlapped letter gets
an animation moving it to its original location.

Next Steps:  
Add UI/UX elements informing the user they are correct. Allowing them to skip a letter or move on to the next puzzle. 
Will likely add a red arrow for skipping and a gold arrow for advancing. The gold arrow will be hidden until correct,
the red arrow will hide once correct.
Will show user what the last word was.

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
