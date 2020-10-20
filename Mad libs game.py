#!/usr/bin/env python
# coding: utf-8

# In[ ]:


""" Mad Libs Generator
----------------------------------------
"""
#Loop back to this point once code finishes
loop = 1
while (loop < 10):
#All the questions that the program asks the user
    noun1 = input("Choose 1st noun: ")
    noun2 = input("Choose 2nd noun: ")
    noun3 = input("Choose 3rd noun: ")
    place = input("Name a place: ")
    adjective = input("Choose an adjective (Describing word): ")
#Displays the story based on the users input
    print ("------------------------------------------")
    print ("Hello ",noun1,",")
    print ("Myself ", noun2,",")
    print ("Welcome to ",place)
    print ("Today's weather is ",adjective,".")
    print ()
    print ("I think you want to meet",noun3,",")
    print ("Well here he is.")
    print ("------------------------------------------")
#Loop back to "loop = 1"
    loop = loop + 1

