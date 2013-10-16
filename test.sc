@player
#1
&ViewMover

&GLView
>x=0.0f
>y=1.0f
>z=2.0f
>ry=180.0f

@planet1
#3
&GLIcoSphere
>x=-500.0f
>y=0.0f
>z=300.0f
>scale=100.0f

@planet2
#2
&GLIcoSphere
#1
>x=-500.0f
>y=0.0f
>z=8000.0f
>scale=1000.0f

@planet3
#3
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

&AABBTree
>ry=180.0f
>meshFile=Rooms/Room1/room1.objs
>subdivisions=4i
>halfsize=2.5f

@northtway
#11
&GLMesh
>scale=1.0f
>z=5.0f
>ry=180.0f
>meshFile=Rooms/Room2/room2.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=5.0f
>ry=180.0f
>meshFile=Rooms/Room2/room2.objs
>subdivisions=4i
>halfsize=2.5f

@northtwayeastexit
#12
&GLMesh
>scale=1.0f
>z=5.0f
>x=-5.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=5.0f
>x=-5.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones
>subdivisions=4i
>halfsize=2.5f

@easttway
#13
&GLMesh
>scale=1.0f
>x=-5.0f
>ry=90.0f
>meshFile=Rooms/Room6/room6.objs
>cullface=nones

&AABBTree
>scale=1.0f
>x=-5.0f
>ry=90.0f
>meshFile=Rooms/Room6/room6.objs
>subdivisions=4i
>halfsize=2.5f

@easttwayeastexit
#14
&GLMesh
>scale=1.0f
>x=-10.0f
>meshFile=Rooms/Room4/room4.objs
>cullface=nones

&AABBTree
>scale=1.0f
>x=-10.0f
>meshFile=Rooms/Room4/room4.objs
>subdivisions=4i
>halfsize=2.5f

@easthanger
#15
&GLMesh
>scale=1.0f
>x=-20.0f
>meshFile=Rooms/Hanger/hanger.objs
>cullface=nones

&AABBTree
>scale=1.0f
>x=-20.0f
>meshFile=Rooms/Hanger/hanger.objs
>subdivisions=4i
>halfsize=10.0f

@easttwaysouthexit
#16
&GLMesh
>scale=1.0f
>z=-5.0f
>x=-5.0f
>ry=180f
>meshFile=Rooms/Room3/room3.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-5.0f
>x=-5.0f
>ry=180f
>meshFile=Rooms/Room3/room3.objs
>subdivisions=4i
>halfsize=2.5f

@easthangersouthexit
#17
&GLMesh
>scale=1.0f
>z=-5.0f
>x=-10.0f
>meshFile=Rooms/Room3/room3.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-5.0f
>x=-10.0f
>meshFile=Rooms/Room3/room3.objs
>subdivisions=4i
>halfsize=2.5f

@eastmostcornerhallway
#18
&GLMesh
>scale=1.0f
>z=-10.0f
>x=-10.0f
>ry=270.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-10.0f
>x=-10.0f
>ry=270.0f
>meshFile=Rooms/Room5/room5.objs
>subdivisions=4i
>halfsize=2.5f

@southeasthallway
#19
&GLMesh
>scale=1.0f
>z=-10.0f
>x=-5.0f
>meshFile=Rooms/Room4/room4.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-10.0f
>x=-5.0f
>meshFile=Rooms/Room4/room4.objs
>subdivisions=4i
>halfsize=2.5f

@souththallway
#20
&GLMesh
>scale=1.0f
>z=-5.0f
>meshFile=Rooms/Room6/room6.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-5.0f
>meshFile=Rooms/Room6/room6.objs
>subdivisions=4i
>halfsize=2.5f

@south4way
#21
&GLMesh
>scale=1.0f
>z=-10.0f
>meshFile=Rooms/Room7/room7.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-10.0f
>meshFile=Rooms/Room7/room7.objs
>subdivisions=4i
>halfsize=2.5f

@northtwaywestexit
#22
&GLMesh
>scale=1.0f
>z=5.0f
>x=5.0f
>ry=90.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=5.0f
>x=5.0f
>ry=90.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones
>subdivisions=4i
>halfsize=2.5f

@westtway
#23
&GLMesh
>scale=1.0f
>x=5.0f
>ry=270.0f
>meshFile=Rooms/Room6/room6.objs
>cullface=nones

&AABBTree
>scale=1.0f
>x=5.0f
>ry=270.0f
>meshFile=Rooms/Room6/room6.objs
>subdivisions=4i
>halfsize=2.5f

@westtwaywestexit
#24
&GLMesh
>scale=1.0f
>x=10.0f
>meshFile=Rooms/Room4/room4.objs
>cullface=nones

&AABBTree
>scale=1.0f
>x=10.0f
>meshFile=Rooms/Room4/room4.objs
>subdivisions=4i
>halfsize=2.5f

@westhanger
#25
&GLMesh
>scale=1.0f
>z=-5.0f
>x=20.0f
>ry=180f
>meshFile=Rooms/Hanger/hanger.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-5.0f
>x=20.0f
>ry=180f
>meshFile=Rooms/Hanger/hanger.objs
>subdivisions=5i
>halfsize=20.0f

@westtwaysouthexit
#26
&GLMesh
>scale=1.0f
>z=-5.0f
>x=5.0f
>ry=90.0f
>meshFile=Rooms/Room3/room3.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-5.0f
>x=5.0f
>ry=90.0f
>meshFile=Rooms/Room3/room3.objs
>subdivisions=4i
>halfsize=2.5f

@westhangersouthexit
#27
&GLMesh
>scale=1.0f
>z=-5.0f
>x=10.0f
>ry=270.0f
>meshFile=Rooms/Room3/room3.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-5.0f
>x=10.0f
>ry=270.0f
>meshFile=Rooms/Room3/room3.objs
>subdivisions=4i
>halfsize=2.5f

@westmostcornerhallway
#28
&GLMesh
>scale=1.0f
>z=-10.0f
>x=10.0f
>ry=180.0f
>meshFile=Rooms/Room5/room5.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-10.0f
>x=10.0f
>ry=180.0f
>meshFile=Rooms/Room5/room5.objs
>subdivisions=4i
>halfsize=2.5f

@southwesthallway
#29
&GLMesh
>scale=1.0f
>z=-10.0f
>x=5.0f
>meshFile=Rooms/Room4/room4.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-10.0f
>x=5.0f
>meshFile=Rooms/Room4/room4.objs
>subdivisions=4i
>halfsize=2.5f

@airlock
#30
&GLMesh
>scale=1.0f
>z=-15.0f
>ry=90.0f
>meshFile=Rooms/Room9/room9.objs
>cullface=nones

&AABBTree
>scale=1.0f
>z=-15.0f
>meshFile=Rooms/Room9/room9.objs
>subdivisions=4i
>halfsize=2.5f

@ship
#4
&GLMesh
>scale=0.1f
>z=-3.0f
>y=0.75f
>x=-18.0f
>meshFile=shipobj/ship.objs
>cullface=nones

&AABBTree
>scale=0.1f
>z=-3.0f
>y=0.75f
>x=-18.0f
>meshFile=shipobj/ship.objs
>subdivisions=4i
>halfsize=50.0f
