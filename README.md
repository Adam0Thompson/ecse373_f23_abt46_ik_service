# ik_service package
This package creates a service, as well as a new message type for use in the ariac competition. The created service takes a part pose as input, and will return several sets of joint angles for the robot to move the robot to that pose, as well as the amount of possible solutions there are.

## how to use
the service package can be run simply using the launch file ik_service.launch

once this service is launched, you can use the following to test its functionality
> rosrun ik_service ik_client_node
It should return that there are 4 possible solutions. 

You can also test using
> rosservice call /pose_ik "part_pose:
>  position:
>    x: 0.5
>    y: 0.0
>    z: 0.0
>  orientation:
>    x: 0.0
>    y: 0.0
>    z: 0.0
>    w: 0.0" 

which should give an output of 
>num_sols: 4
>joint_solutions: 
>    joint_angles: [341829.65625, 2.3785343170166016, -9.086013237356023e-17, 2.3763046264648438, 1.2682847724178477e-15, 1.8592097759246826]
>
>    joint_angles: [3.127365297771835e+25, 2.252366065979004, 2.3810739606543875e+38, 2.2945241928100586, 2.374705318512376e+31, 2.2803595066070557]
>
>    joint_angles: [341829.65625, 2.3785343170166016, -1.0408480694620804e-22, 1.776806116104126, -1.170121156740724e-29, 2.334146499633789]
>
>    joint_angles: [-4.22191501711015e+29, 2.315124988555908, 2.3810739606543875e+38, 2.2945241928100586, 2.374705318512376e+31, 2.2803595066070557]
>
>    joint_angles: [3.0792602013944365e+26, 2.1710283756256104, -1.5149992371732424e-11, 2.066795825958252, 1.2682847724178477e-15, 1.8592097759246826]
>
>    joint_angles: [1.1570520669720107e-30, 2.273923397064209, 3370280812544.0, 1.9463495016098022, -2.0068117433738834e-32, 2.3086888790130615]
>
>    joint_angles: [3.0792602013944365e+26, 2.1710283756256104, -3.946713178493155e-08, 2.175487518310547, -1.170121156740724e-29, 2.334146499633789]
>
>    joint_angles: [-1.5278662634552423e-26, 2.3366823196411133, 3370280812544.0, 1.9463495016098022, -2.0068117433738834e-32, 2.3086888790130615]

