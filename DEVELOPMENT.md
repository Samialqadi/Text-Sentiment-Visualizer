# Development Log
## In Progress
- Extend program with music

## Completed
- Testing with Catch
- Parse JSON from API with library
- Displaying sentences on GUI foreground
- Changing color of particles background per the emotion of the text
- Added Legend for what color maps to what emotion
- Explore openFrameworks GUI functionalities
- Explored JSON library
- Explored IBM Watson API
- Make API calls through https://github.com/mrtazz/restclient-cpp
- Mockup designs for UI

## Week 0
It took quite a while to find the libraries and API that I needed to use for my project. So far, I've demoed the IBM Watson API and it seems to work brilliantly as it correctly deciphers the emotion from all unambiguous bodies of text. Also, the wrapper library for openFrameworks seems to do a good job of parsing JSON.

## Week 1
I have added another library from what I initially thought I needed in order to make POST requests to the API. I had to go through many different libraries in order to find one that wasn't convoluted and poorly documented. I ended up with https://github.com/mrtazz/restclient-cpp and with this I can now call the API.
I have also added yet another library from what I initially intended to parse JSON as this one is much more popular and better documented. 
https://github.com/open-source-parsers/jsoncpp
Moving away from the technical side of things, I created mockup GUI designs to help guide me throughout the frontend development of the project. These can be found at https://imgur.com/a/sbkLiQH

## Week 2
I successfully linked the API and all libraries together. I still need to extensively test these functionalities to make sure I don't move forward with faulty code. Also, I was able to figure out how to take user input through a text box, although it wasn't in the fashion that I would've liked. I was hoping to have a normal text box on the GUI landing page, however text boxes from ofGui were extremely ugly and not what I was hoping for, so I resorted to a pop up window style text box. Moving forward, I need to implement my particle system to work in the fashion that I would like, and perhaps implement further functionalities if I get the chance.

## Week 3
After much difficulty, I have accomplished the minimum viable product. The GUI is now fully functional and shows the emotion of each sentence by adding particles of the respective color to the background of the program. Also, I was able to add a legend that shows what color maps to what emotion because some of them aren't entirely all the easy to assume. Moving forward, I would like to extend the project further by adding in elements of music and perhaps text to scene generation. I would have loved to implement some of these features, however it proved to be quite difficult and requires more time.
