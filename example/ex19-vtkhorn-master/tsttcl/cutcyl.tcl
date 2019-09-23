# test cutting cylinder by plane

vtkBox box
box SetBounds -.8 .8 -.8 .8 0 .8

vtkCylinder cyl
cyl SetCenter 0 0 0
cyl SetRadius 0.5

vtkPlane pln1
pln1 SetOrigin 0 -.4 0
pln1 SetNormal 0 1 0

vtkPlane pln2
pln2 SetOrigin 0 .4 0
pln2 SetNormal 0 -1 0


vtkImplicitBoolean ib1
ib1 SetOperationTypeToDifference
ib1 AddFunction cyl
ib1 AddFunction pln1
ib1 AddFunction pln2

vtkImplicitBoolean ib2
ib2 SetOperationTypeToDifference
ib2 AddFunction box
ib2 AddFunction ib1

vtkSampleFunction smpl
smpl SetImplicitFunction ib2
smpl SetSampleDimensions 20 20 20
smpl SetModelBounds -1 1 -1 1 -1 1
smpl ComputeNormalsOff
smpl SetOutputScalarTypeToDouble

vtkContourFilter srf
srf SetInput [smpl GetOutput]
srf SetValue 0 0.0

vtkPolyDataMapper map
map SetInput [srf GetOutput]
map ScalarVisibilityOff

vtkCamera cam

vtkCubeAxesActor2D axes
axes SetInput [srf GetOutput]
axes SetCamera cam
axes SetLabelFormat "%6.2g"
axes SetFlyModeToOuterEdges
axes SetFontFactor 0.8
[axes GetProperty] SetColor 0 0 0

vtkActor act
act SetMapper map
[act GetProperty] SetColor 1 0 0

vtkRenderer ren
ren SetActiveCamera cam
ren AddActor act
ren AddViewProp axes
ren SetBackground 1 1 1

#vtkInteractorStyleTrackballActor istyle
vtkInteractorStyleTrackballCamera istyle

vtkRenderWindow rw
rw AddRenderer ren
rw SetSize 250 250

vtkRenderWindowInteractor iren
iren SetRenderWindow rw
iren SetInteractorStyle istyle
iren Initialize

# render the image
#
iren AddObserver UserEvent {wm deiconify .vtkInteract}
rw Render

# prevent the tk window from showing up then start the event loop
wm withdraw .


# vtkImageThreshold thld
# thld SetInputConnection [smpl GetOutputPort]
# thld ThresholdByUpper 0
# thld SetInValue 255
# thld SetOutValue 0
# thld ReplaceInOn
# thld ReplaceOutOn
# thld SetOutputScalarTypeToUnsignedChar
