# Web Based Compiler

## What is the project
* This is a web based compiler
* It is used to compile code in multiple languages


## Tech stack used
* HTML - For structure
* CSS  - For styling
* Bootstrap - For making it more responsive and for adding interface components
* Javascript - For functionality
* jQuery - This is a javascript library which I have used for DOM(document object model) manipulation, for event handling, and to send and recieve data from server without refreshing the page
* Node.js - To execute javascript code outside the web browser in my local system
* Express.js - To create a server

## Modules Used
* Compilex - compilex is a node.js library which is used to build online code editor/compiler websites 
* Ace.js - Ace is a code editor written in JavaScript. The goal is to create a web-based code editor using this prewritten 

## Working
* Choose a language from dropdown option
*  and then write code in Ace code editor,
*  and then select if you want to give input
*  give input
*  and then we will run the code, 
*  an AJAX request would be made with the help of jquery,
*  it will go in backend where the express.js server is running, the request will be fetched and it will be sent to compilex, 
*  then compilex will compile the program and will send output/ error
*  Then jquery will show the output/error on the output screen with the help of DOM manipulation

## Advantages
* Helps during competitive coding
* You don't need to provide input multiple times, input will be saved
* It is fast, as it is running on local system, so there is no need to send the request to any other server
* You can use this without internet
* Does not take time to load, unlike other heavy code editors like vim, atom
* You don't need to create a file or save them to run a code
* Very useful in running small codes, which I don't want to save in my local system

## Modifications which can be made
* Can add the feature of saving the code
* Can add multiple programming languages
* Can add multiple themes for better look
* Can add an option for signup and login, if the user wants to save their work online just like codepen or onlinegdb
* Can scale it up, by load balancing
