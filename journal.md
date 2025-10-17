#Performing Robots Journal - by Ali Noor

## 10/02/2025 - Fixing the Robot base and body frame:

Today was a quite long day. After trying to get around the problem of one of the motors not spinning and working according to program structure, the board and circuit installment including arduino was tested for short circuit. Towards the end the fault was found inside the Arduino board which was later swapped.

<img width="503" height="561" alt="image" src="https://github.com/user-attachments/assets/946bb873-7d74-4c52-b184-547869c248d6" />
<img width="506" height="341" alt="image" src="https://github.com/user-attachments/assets/023f9494-8978-4fba-af64-1c284bca3d10" />

### Demonstration:
https://drive.google.com/file/d/1Nec91-aRDii5MrB84LQ8Sl00QKBiiJDG/view?usp=sharing

The Next step was to build a 1.5 Metre long body with physical characterics to the robot. The wooden plank from Alpine wood was used to build the backbone of the frame, and a lot of sawing, cutting, and drilling was done to manufacture the robot as we advised. Nails were driven into the long plank to attach it to wooden base, and l-brackets were made use of to provide arching support to the plank. 

<img width="421" height="533" alt="image" src="https://github.com/user-attachments/assets/228253f6-c0b7-4410-b4f2-a7ca0bc9affd" />
<img width="493" height="588" alt="image" src="https://github.com/user-attachments/assets/39c20bf6-2006-4eef-9b6b-a5b73b6685ce" />

The final project ended up looking like this:

<img width="400" height="740" alt="image" src="https://github.com/user-attachments/assets/81f2da38-f108-474d-8ecb-a1c1e6ce9a82" />

Overall the robot works as of now in terms of its control;however, the code still requires some adjustment to properly map the input from the controller onto the wheels attached below the base.


## 10/03/2025 - Completing the upper body, alongside face and shoulders:

Today the upper body was the primary target. To acheive this, we needed the shoulder. Hence, a small light weight plank was cut and then was joint to the already existing spine of the character, with nails driven though them. 

<img width="467" height="620" alt="" src="https://github.com/user-attachments/assets/0ae81d77-eb7e-446d-ab4c-9164db47ab8b" />
 To make sure the character isn't tilting, the level was checked and was made sure that no tilt occured.

 After this, the face of the character (Walter White ) was cut-out to be place on the robot. I printed the face and then used cardboard as foundation. Using sharp blade, the cutout of the husband was obtained.
 
<img width="465" height="617" alt="" src="https://github.com/user-attachments/assets/076f1467-328f-4613-bc89-96ed7e1c9d78" />


 <img width="399" height="505" alt="" src="https://github.com/user-attachments/assets/b20d597f-22fa-4532-931e-365a14b10416" />

 After this, the shredded body was the next on the agenda. Same procedure as the face was replicated and a defined front and back was made.
 

 <img width="412" height="602" alt="" src="https://github.com/user-attachments/assets/255a532a-d6a8-4082-8132-7a6ffedc5f1c" />
<img width="437" height="549" alt="" src="https://github.com/user-attachments/assets/5ff1f230-ccb1-4ec2-8381-6382bc642340" />

Towards the end, we had a semi-realistic character coming along !

<img width="377" height="575" alt="" src="https://github.com/user-attachments/assets/9e37e0ed-4664-4c88-9a45-dbb02f38a98b" />

## 10/07/2025 - Completing the arms and fore-arms of the robot:
Today's class was short and concise. The arms and forearms of the robot were on today's agenda. The robot was planned to have movement along y-axis only, however; I decided to incorporate a y-axis 2 dimensional movement as well. For this, most of the time was spent cutting the planks for the arms.

Man in action video : 
https://drive.google.com/file/d/1alnSVP_sdz5VeUlvgOLo4V8OtDTKxqrC/view?usp=sharing

## 10/08/2025 - Attaching the servos:

The evening was spent attaching the servos to the robot. Professor Shiloh request at least one, but I ended up attaching 3 servos. One for the face, and the other ones for the shoulder and the fore-arm.
I started with the face first. Since the glue wasn't working well with the wooden plank and the servo's plastic surface, I made use of copper wiring to create a support mesh which anchored both the face, and the motor in place!

<img width="451" height="386" alt="" src="https://github.com/user-attachments/assets/f74b59c9-cf8f-4ff4-a1af-03a9ca4f2ca6" />

<img width="466" height="545" alt="" src="https://github.com/user-attachments/assets/3cfdd8fb-21cf-4f2f-9b6d-23589f8e84f5" />

<img width="465" height="608" alt="" src="https://github.com/user-attachments/assets/802e02ca-8ea0-4da1-98be-a99112f3d46a" />

After the face was put in place alongside it's mini-servo and much wrestling, the next step was to assemble pan-tilt assembly for the 2  degree of freedom movement.

<img width="465" height="598" alt="" src="https://github.com/user-attachments/assets/ab2144d1-a85c-4a9a-aff3-37ae853ebab6" />

Assembling the pan-tilt wasn't hard. Using 4 size wooden drill bit, holes were made for M3 thredded bolt, which were tightened with nuts attached to their ends on the opposite side of the plank. 
The issue I faced was that 10 mm M3s were interefering with the servos (scratching the plastic casing), and I left them partially screwed to the brackets. Overall today was quite a  productive day! 

## 10/09/2025 - Arduino Mega 2560, PCB, and complementary attachments:
Today while in class, new shield was provided. This was screwed onto the upper portion of the spine of the character for easy access. Wire extentions were added onto the servo motors to elongate the wire length. These wires (ground, vcc, and signal) were connected to the custom PCB, which traced onto the connection to D20, D21, D19, D17, D16, and D18 pin on the Mega Board. This new additional board has more pin connections to accommodate additional sensors, and accessory connections such as the servos themselves.

<img width="459" height="483" alt="" src="https://github.com/user-attachments/assets/11ba4087-5f70-40ec-abe3-24614e23b8e5" />

<img width="367" height="501" alt="" src="https://github.com/user-attachments/assets/2636bebc-b151-4aab-a82b-1498f4eefe46" />

M3 but of 5mm length were also provided by Professor Shiloh. These were swapped into the place of 10 mm M3s. Now the motor functions freely without any obstruction provided by the protuding ends of the 10 mm M3 bolts.
Also, pan and tilt steering brackets were re-assmebled, and were put in place, while attaching the arms and fore-arms. As can be seen in the images attached, The upper body is complete. We haven't attached the back yet, as wiring is still being worked on!

## 10/16/2025 - Arduino Mega 2560 programming and fixing robot:

The Fall break is still going on, but I somehow ended up finding myself in IM lab - tempted to finish and tidy up the robot! The main to-dos included programming Mega 2560 board, hot-gluing sharp edges of nails protuding out of the one end of wood, tightening the loose bolts and attaching missing nuts to the base, and screwing in brackets for the 7th servo which will be responsible for moving the mouth of the character.

First I experimented with the code. Here is the outcome:
https://drive.google.com/file/d/1b9hzDDYds8vl3-gCu5K6J5y6UNM2000q/view?usp=sharing

The issue I came across was the voluntary movement of either of the servos, when the code was not even adressing them!
When I tried to move the shoulder, it ended up moving the fore-arm servo! When the arm servo was ought to be engaged, shoulder would tilt. Perhaps it occured to due to my limited knowledge of servos, or power supply. Therefore I checked the wiring again, including the wires responsible for 5 Volt supply to the PCB board. The source powering the servos is Anker's power bank. I suspect it cannot regulate the supply and therefore results in improper motor movement. 
35 kg servo draws 10 Amperes at the very least, and 60 W power draw. I don't think power bank can manage that - infact might damage it.
Therefore I stopped the experiment. The circuity of the PCB is as follows:


<img width="646" height="607" alt="Sketch" src="https://github.com/user-attachments/assets/c4c77456-b1c3-44c4-b1b1-4b61d370a151" />

![IMG_0316](https://github.com/user-attachments/assets/ff64c9b9-a589-4b22-8f6a-d41ab4a95f2c)

The second order of affair was fixing the robot.

Loose bolts were tightened with adjustable wrench, and missing nuts were added.
 
![IMG_0320](https://github.com/user-attachments/assets/6bbf4645-0849-4162-972c-fb2d452a30d3)

 The robot was then laid flat accross the table to access the surface under the base. Sharp ends of the screws sticking out were covered with foam sheet.
 
 ![IMG_0318](https://github.com/user-attachments/assets/657d7f56-23f1-420f-b8ae-55b41f7461bb)

  Hot glue was added to long ends of the nails as well:
  
![IMG_0322](https://github.com/user-attachments/assets/3662e672-6be7-4f68-9ae4-08af88e0adee)

Last but not the least, the 7 th servo was added, with bracket first screwed in, and then bolt through the cardboard into the servo put in place in order to hold the lower jaw together. The Upper portion of the face was attached using sticky tacks - which surprisingly worked well on wood and cardboard!

![IMG_0330](https://github.com/user-attachments/assets/f2732dd9-f0fd-4737-9301-97b68fe9cc47)

Functioning mouth demo video:
https://drive.google.com/file/d/1BLw5ea6p88XmwloBGs09D-tmAa9ACn6C/view?usp=sharing

Conclusion: The robot is coming together and need to work on code now to finish the implementation of servos.

I treated myself to ice-cream sandwhich at 2 a.m and went out for a walk as I concluded my adventure for the day!

![IMG_0333](https://github.com/user-attachments/assets/9992c0ea-208b-49b8-9f45-6ec91bceca5b)


P.S professor I found your favourite pointing stick sitting right next to the arts supply cupboard in IM lab :

![IMG_0315](https://github.com/user-attachments/assets/d98f5a7d-97eb-43d7-abb6-7ae06025eb50)






 
