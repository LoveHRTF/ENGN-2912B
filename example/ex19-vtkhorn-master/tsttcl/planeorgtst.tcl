# test cutting cylinder by plane
vtkSphereSource sph
sph SetCenter 0 0 0
sph SetRadius 0.1

vtkPlane pln
pln SetOrigin 0 0 0
pln SetNormal 1 1 1

vtkSampleFunction smpl
smpl SetImplicitFunction pln
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

vtkPolyDataMapper sphmap
sphmap SetInput [sph GetOutput]
sphmap ScalarVisibilityOff


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
[act GetProperty] SetColor 0 0 1

vtkActor sphact
sphact SetMapper sphmap
[sphact GetProperty] SetColor 1 0 0


vtkRenderer ren
ren SetActiveCamera cam
ren AddActor act
ren AddActor sphact
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
