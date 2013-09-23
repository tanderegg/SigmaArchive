@planet1
#3
&GLIcoSphere
>x=-500.0f
>y=0.0f
>z=300.0f
>scale=100.0f

@planet2
#4
&GLIcoSphere
>x=-500.0f
>y=0.0f
>z=8000.0f
>scale=1000.0f

@planet3
#5
&GLIcoSphere
>x=-500.0f
>y=0.0f
>z=2000.0f
>scale=500.0f

@mars
#6
&GLCubeSphere
>scale=1000.0f
>x=4000.0f
>y=0.0f
>z=0.0f
>texture_name=marss
>subdivision_levels=5i
>shader=cubespheres
>rotation_speed=0.01f

@ship
#7
&GLMesh
>scale=1.0f
>x=40.0f
>meshFile=trillek_dev_ship_2_clonk2u_window.objs
>cullface=nones

@stars
#8
&GLCubeSphere
>scale=1000.0f
>texture_name=starss
>subdivision_levels=3i
>shader=skyboxs
>cullface=fronts
>fix_to_camera=1b

@ship2
#9
&GLMesh
>scale=10.0f
>x=-40.0f
>meshFile=ship3.objs