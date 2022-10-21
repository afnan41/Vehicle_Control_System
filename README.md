# Vehicle_Control_System
Implement vehicle Control System 
>### System specifications: 
1 . User choose weather to:<br>
&emsp;*a. Turn on the vehicle engine.*<br>
&emsp;*b. Turn off the vehicle engine.*<br>
&emsp;*c. Quit the system.*<br>

2. Once a choice has been made, the system state is displayed.<br>
3. ***`Turn on the vehicle engine`*** displays the **Sensors set menu**, which simulates the vehicle sensors readings:<br>
&emsp;*a. Turn off the engine.*<br>
&emsp;*b. Set the traffic light color.*<br>
&emsp;*c. Set the room temperature (Temperature Sensor).*<br>
&emsp;*d. Set the engine temperature (Engine Temperature Sensor).*<br>
4. While the engine is ON, **Sensors set menu** is always displayed, and the dashboard waits for an input.<br>
5. Based on the input taken:<br>
**a. Based on traffic light data received from a sensor:**<br>
&emsp;&emsp;i. If the traffic light is ‘G’ set vehicle speed to 100 km/hr<br>
&emsp;&emsp;ii. If the traffic light is ‘O’ set vehicle speed to 30 km/hr<br>
&emsp;&emsp;iii. If the traffic light is ‘R’ set vehicle speed to 0 km/h<br>
**b. Based on room temperature data from temperature sensor:**<br>
&emsp;&emsp;i. If temperature less than 10, Turn AC ON and set temperature to 20<br>
&emsp;&emsp;ii. If temperature is greater than 30, Turn AC ON and set temperature to 20<br>
&emsp;&emsp;iii. If temperature is otherwise, Turn AC OFF<br>
**c. Based on engine temperature data from engine temperature sensor:**<br>
&emsp;&emsp;i. If temperature less than 100, Turn “Engine Temperature Controller” ON and set temperature to 125<br>
&emsp;&emsp;ii. If temperature is greater than 150, Turn “Engine Temperature Controller” ON and set temperature to 125v<br>
&emsp;&emsp;iii. If temperature is otherwise, Turn “Engine Temperature Controller” OFF<br>
**d. If vehicle speed is 30 km/hr:**<br>
&emsp;&emsp;i. Turn ON AC if it was OFF and set room temperature to: current temperature * (5/4) + 1<br>
&emsp;&emsp;ii. Turn ON “Engine Temperature Controller” if it was OFF and set engine temperature to: current temperature * (5/4) + 1<br>
**e. Display the current vehicle state after applying any of the above options:**<br>
&emsp;&emsp;i. Engine state: ON/OFF.<br>
&emsp;&emsp;ii. AC: ON/OFF.<br>
&emsp;&emsp;iii. Vehicle Speed.<br>
&emsp;&emsp;iv. Room Temperature.<br>
&emsp;&emsp;v. Engine Temperature Controller State.<br>
&emsp;&emsp;vi. Engine Temperature.<br>
***Notice that: In the simulation, the sensor read values are taken as an input from the console***<br>

