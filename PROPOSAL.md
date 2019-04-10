# Final Project Proposal
## My background
I am a CS + Ling major, so I have a good idea by now of linguistic sentiment analysis. For this project, much of the NLP will be taken off my shoulders through the API used, however I will likely find my background useful when it comes to extending the project later on. Also, I have experience implementing APIs and JSON from this course and previous courses, so I should be able to use these experiences for the project's success.
## What I want my project to do:
I would like my project to visualize a body of text. 
### Minimum Viable Product: 
A program that is able to take a body of text and display the emotions (Anger, Fear, Joy, Sadness, Analytical, Confident, Tentative) through colors. 
The colors would be the typical colors that represent certain emotions. 
* For example: 
  * Red: Anger, embarrassment, passionate, and lustful. 
  * Blue: Shyness, sadness, and calmness. 
  * Yellow: Cowardice, happiness, or caution. 
  * Green: Disgust, envy, sickness, friendly, or greedy. 
  * Grey: Depression and emotionless. 
  * Black: Cold or mournful. 
  * Pink: Cheery, embarrassed, and love. 
  * White: Sick, shocked, scared, cold, and mournful.
### Ambitious goals given endless time and resources:
The program would be extended to introduce elements such as sound, perhaps more specific visuals to perfectly represent what the text is speaking about. For example, if the text is a poem about a house on a rainy day, the program would display a house along with sounds and colors that give off a more depressing vibe. Other ideas include introducing live speech to text with the program being able to do more than just display colors based on a body of text, but rather it would constantly update as a user is speaking. This could be useful for presentations such as poetry events, comedy shows, etc. 

## What libraries or resources I have identified to use for this project:
I will certainly be using openFrameworks. For my sentiment analysis I will be using IBM Watson's Tone Analyzer API. To parse the JSON that this API will provide, I will be using a wrapper library for openFrameworks.
### Links to outside resources:
* API: https://www.ibm.com/watson/services/tone-analyzer/ 
* JSON: https://github.com/jeffcrouse/ofxJSON
