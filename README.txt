Elliptical Orbits

We slove Kepler's equations via Newton-Raphson iteration to visualize a stallite's orbit.


***Physics***

Consider a satellite orbiting the earth with period P whose distances of closest and farthest approach are r1 and r2, Then the satellite’s path traces out an ellipse,
r(θ)= 1+ecos(θ)/a(1−e^2)=a(1−ecosE)

The formula above assumes polar coordinates (r,θ) in the lane of the orbit with the earth centred on one of the ellipse’s foci. The ratio
e= (r1-r2)/(r2+r1)= (r1-r2)/2a defines the eccentricity of the orbit; a is the semi-major axis, and E is the so-called eccentric anomaly.

Kepler worked out the following procedure for determining the location of the satellite at time t, as measured from the moment of closest approach:

1.Define the mean anomaly M=2πt/P.
2.Determine the eccentric anomaly E by solving Kepler’s equation, M=E−esinE.
3. Compute the true anomaly θ from the equation tan(θ/2) = (1−e/1+e)^(1/2) tan(E/2)
 
Kepler’s equation is transcendental and has no closed-form solution. It has to be inverted numerically.


***Programm***

In the file " orbit.cpp", we solve Kepler’s equation by finding the root of the function f(E)=E−M−esinE via Newton-Raphson iteration:
E (n+1) := E(n)− f(E (n))/f'(E (n)) = E(n) − (E(n)−M−esinE(n)/1-ecosE(n))
In "orbit.cpp" the closest- and farthest-approach values were set to r1 = Re+500km and r2 = Re+3000km, where Re is the radius of the earth.

The output of this code, "o.dat" is a series of lines with three columns of values: time (in hours), radius (in kilometers), and true anomaly (in radians). The output can be analyzed and plotted to visualize the satellite's orbit and how it changes over time.

The view1.gp script gives you the following plots in GNUplot,
1. distance vs. time
2. polar angle vs. time
3. y postion vs. x position

Follow these commands to run this script.
g++ -o orbit orbit.cpp --> run C++ script
./orbit o.dat --> gives o.dat output file
gnuplot -persist view1.gp --> gives above three plots

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
