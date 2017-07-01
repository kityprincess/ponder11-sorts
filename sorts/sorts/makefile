###############################################################
# Program:
#     Week 11, Sorts
#     Brother JonesL, CS265
# Author:
#     Bryan Lopez    - 3 hours
#     Kimberly Stowe - 5 hours
#     Matthew Burr   - 6 hours
#     Shayla Nelson  - 5 hours
# Summary:
#     This program runs through 7 different sorts and compares
#          their efficiency.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week11.o
	g++ -o a.out week11.o -g
	tar -cf week11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week11.o     : the driver program
##############################################################
week11.o: bnode.h bst.h stack.h week11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h
	g++ -c week11.cpp -g

