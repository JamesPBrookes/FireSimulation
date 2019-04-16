# Fire Simulation

The simulation displays a grid of 21x21 cells with a boundary on the outside which acts as a fire breaker and trees on the inside of the boundary. When the simulation starts, there is a burning tree in the middle of the grid. When the simulation starts, the user is prompted to press a key to start the simulation, when they press the key, the system redraws the grid and displays which trees have been burnt, are burning or are still trees. After each step the user is again prompted to either press a key to advance the simulation or Q to quit. Once the user presses a key, the next ‘time step’ of the simulation is calculated and displayed, each tree around the burning one has a 50% chance of catching on fire, the simulation ends when either the user presses the Q key or there are no more burning trees.

The simulation produces a different result each time and works according to the requirement specification we were given. 
The design is alsoobject oriented using three classes. It uses a header file for the class definitions and global variables. 
The classes have both private and public variables and the Cell class has its own getter and setter methods. 
Each class also has a constructor and deconstructor.
Despite having 3 classes the code is rather procedural. Class forest is simply a 2D array which could have been declared 
outside of a class
