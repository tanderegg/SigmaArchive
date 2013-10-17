@player
#1
&ViewMover

&GLFPSView
>x=0.0f
>y=2.0f
>z=0.0f
>ry=180.0f

@planet2
#3
&GLIcoSphere
#1
>x=-500.0f
>y=0.0f
>z=8000.0f
>scale=1000.0f

@planet3
#4
&GLIcoSphere
#1
>x=-500.0f
>y=0.0f
>z=2000.0f
>scale=500.0f

@center
#10
&GLMesh
>scale=1.0f
>ry=180.0f
>meshFile=Rooms/Room1/room1.objs
>cullface=nones

&BulletShapeMesh
>ry=180.0f
>meshFile=Rooms/Room1/room1.objs

@northtway
#11
&GLMesh
>scale=1.0f
>z=5.0f
>ry=180.0f
>meshFile=Rooms/Room2/room2.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=5.0f
>ry=180.0f
>meshFile=Rooms/Room2/room2.objs

@northtwayeastexit
#12
&GLMesh
>scale=1.0f
>z=5.0f
>x=-5.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=5.0f
>x=-5.0f
>meshFile=Rooms/Room5/room5.objs

@easttway
#13
&GLMesh
>scale=1.0f
>x=-5.0f
>ry=90.0f
>meshFile=Rooms/Room6/room6.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>x=-5.0f
>ry=90.0f
>meshFile=Rooms/Room6/room6.objs

@easttwayeastexit
#14
&GLMesh
>scale=1.0f
>x=-10.0f
>meshFile=Rooms/Room4/room4.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>x=-10.0f
>meshFile=Rooms/Room4/room4.objs

@easthanger
#15
&GLMesh
>scale=1.0f
>x=-20.0f
>meshFile=Rooms/Hanger/hanger.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>x=-20.0f
>meshFile=Rooms/Hanger/hanger.objs

@easttwaysouthexit
#16
&GLMesh
>scale=1.0f
>z=-5.0f
>x=-5.0f
>ry=180f
>meshFile=Rooms/Room3/room3.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-5.0f
>x=-5.0f
>ry=180f
>meshFile=Rooms/Room3/room3.objs

@easthangersouthexit
#17
&GLMesh
>scale=1.0f
>z=-5.0f
>x=-10.0f
>meshFile=Rooms/Room3/room3.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-5.0f
>x=-10.0f
>meshFile=Rooms/Room3/room3.objs

@eastmostcornerhallway
#18
&GLMesh
>scale=1.0f
>z=-10.0f
>x=-10.0f
>ry=270.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-10.0f
>x=-10.0f
>ry=270.0f
>meshFile=Rooms/Room5/room5.objs

@southeasthallway
#19
&GLMesh
>scale=1.0f
>z=-10.0f
>x=-5.0f
>meshFile=Rooms/Room4/room4.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-10.0f
>x=-5.0f
>meshFile=Rooms/Room4/room4.objs

@souththallway
#20
&GLMesh
>scale=1.0f
>z=-5.0f
>meshFile=Rooms/Room6/room6.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-5.0f
>meshFile=Rooms/Room6/room6.objs

@south4way
#21
&GLMesh
>scale=1.0f
>z=-10.0f
>meshFile=Rooms/Room7/room7.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-10.0f
>meshFile=Rooms/Room7/room7.objs

@northtwaywestexit
#22
&GLMesh
>scale=1.0f
>z=5.0f
>x=5.0f
>ry=90.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=5.0f
>x=5.0f
>ry=90.0f
>meshFile=Rooms/Room5/room5.objs

@westtway
#23
&GLMesh
>scale=1.0f
>x=5.0f
>ry=270.0f
>meshFile=Rooms/Room6/room6.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>x=5.0f
>ry=270.0f
>meshFile=Rooms/Room6/room6.objs

@westtwaywestexit
#24
&GLMesh
>scale=1.0f
>x=10.0f
>meshFile=Rooms/Room4/room4.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>x=10.0f
>meshFile=Rooms/Room4/room4.objs

@westhanger
#25
&GLMesh
>scale=1.0f
>z=-5.0f
>x=20.0f
>ry=180.0f
>meshFile=Rooms/Hanger/hanger.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-5.0f
>x=20.0f
>ry=180.0f
>meshFile=Rooms/Hanger/hanger.objs

@westtwaysouthexit
#26
&GLMesh
>scale=1.0f
>z=-5.0f
>x=5.0f
>ry=90.0f
>meshFile=Rooms/Room3/room3.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-5.0f
>x=5.0f
>ry=90.0f
>meshFile=Rooms/Room3/room3.objs

@westhangersouthexit
#27
&GLMesh
>scale=1.0f
>z=-5.0f
>x=10.0f
>ry=270.0f
>meshFile=Rooms/Room3/room3.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-5.0f
>x=10.0f
>ry=270.0f
>meshFile=Rooms/Room3/room3.objs

@westmostcornerhallway
#28
&GLMesh
>scale=1.0f
>z=-10.0f
>x=10.0f
>ry=180.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-10.0f
>x=10.0f
>ry=180.0f
>meshFile=Rooms/Room5/room5.objs

@southwesthallway
#29
&GLMesh
>scale=1.0f
>z=-10.0f
>x=5.0f
>meshFile=Rooms/Room4/room4.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-10.0f
>x=5.0f
>meshFile=Rooms/Room4/room4.objs

@airlock
#30
&GLMesh
>scale=1.0f
>z=-15.0f
>ry=90.0f
>meshFile=Rooms/Room9/room9.objs
>cullface=nones

&BulletShapeMesh
>scale=1.0f
>z=-15.0f
>ry=90.0f
>meshFile=Rooms/Room9/room9.objs

@ship
#5
&GLMesh
>scale=0.1f
>z=-3.0f
>y=0.75f
>x=-18.0f
>meshFile=shipobj/ship.objs
>cullface=nones