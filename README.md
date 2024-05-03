# CS310-Spring2024-CP4
So, Ill mostly use this to keep important info. -KF 4/20 
-----------------------------------------------------------------------------------------------------------
**Helpful Info**
-----------------------------------------------------------------------------------------------------------
    How does the program know to delete a specific node in a heap? 
        Well, the BST will store the index in the heap, then this index will be passed to the remove function in the heap!!! -KF 4/20
    How do I push to my Branch?
        For me(Kian) I type the following in the unix terminal
            git add *
            git commit -m "Your message goes here"
            git push origin <branch_name> (My branch name is Kian-branch. Watch out for spelling or case errors!!!)
        -KF 4/21   
-----------------------------------------------------------------------------------------------------------

Kian's Log
-----------------------------------------------------------------------------------------------------------
12:56PM 4/20/2024:
    This is a log so others can keep track of my work. If you want to start your own that is fine but no pressure.
    I made some changes to Heap, adding lots of auxiliary functions and some core functions that still need testing such as PercolateDown,Remove and swap. Signing off at 1:00PM to do work for CS373. Will work on this further later time if possible but for certain Sunday.
-----------------------------------------
1:59PM 4/21/2024:
    Tested swap,pop,and percolateDown(). Remove has been tested but only in the context of removing the head.
-----------------------------------------
2:33PM 4/21/2024:
    Remove has been fully tested. Pop(),PercolateDown() and Remove() were tested by compairing output from CMD prompt to https://visualgo.net/en/heap when the array had the same content and function call sequene.
-----------------------------------------
3:05PM 4/21/2024:
    Have to rewrite Remove() to be compliant with what Lewis described. Logging off to work on stats RN.  
-----------------------------------------
9:50PM 4/21/2024:
    Added bool removed to song along with getter and setter. Remove function does not need to be changed according to lewis.   
-----------------------------------------
10:45AM 4/28/2024:
    Starting work on remove and favorite in manager object.    
-----------------------------------------
11:18AM 4/28/2024:
    Leaving remove to Jackson as he requested. Finished favorite and am now pushing untested code to my branch so I can pull to VS Community '22 cuz I like that debugger. 
-----------------------------------------
12:41AM 4/28/2024:
    Finished and tested favorite. Works fine but when return 0; is reached in main following issue occurs.
    free(): invalid size
    Aborted 
    I suspect this was a preexisting issue and has some relation to the heap. Manager might need a deconstructor
-----------------------------------------
11:08PM 4/29/2024:
    Made fixes to favorite
-----------------------------------------------------------------------------------------------------------

