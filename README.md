# MARBLE fOKe

This is the solution to the marble hackathon developed by the fOKe team.

# Cloning the code
Clonning the code should be straight forward. Clone the repo\

><code>git clone git@github.com:Zlatanius/MARBLE-Hackathon-Foke.git</code>\

and then run

><code>colcon build --symlink-install</code>

# Running the Project
(Order of opperation is important)
1. Start the grpc server
2. Start the unity simulation
3. Launch the inference and comunication nodes: <code>ros2 launch marble_pkg _launch.py</code>
4. Launch the sufacing nodes: <code>ros2 launch surfacing_script _launch.py</code>

# Credits
Adna Šestić - Inference\
Zlatan Jakić and Amina Pojskić - Comunications\
Aldin Dželo - Localization and surfacing algorithm
