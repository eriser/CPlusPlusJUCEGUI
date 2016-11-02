/*
==============================================================================

This file was auto-generated!

==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
	setSize(800, 500);
}

MainContentComponent::~MainContentComponent()
{
}
//绘制图形
void MainContentComponent::paint(Graphics& g)
{
	//the resized() function is always called whenever anything changes the component's size.
	//This includes the first time the component's size is set and the component is painted after the app launched.
	g.fillAll(isLightblueOrOrange ? Colours::lightblue : Colours::orange);
	g.setColour(Colours::darkblue);
	g.setFont(40.0f);
	g.setColour(Colours::purple);
	g.drawText(L"当前size " + currentSizeAsString, getLocalBounds(), Justification::centred, true);
}
//当改变窗口大小时调用（先调用此函数，再调用paint）
void MainContentComponent::resized()
{
	// This is called when the MainContentComponent is resized.
	// If you add any child components, this is where you should
	// update their positions.
	currentSizeAsString = String(getWidth()) + " x " + String(getHeight());
	if (getWidth() / 100 % 2 == 1) { isLightblueOrOrange = false; }
	else { isLightblueOrOrange = true; }
}
/*
1.Every JUCE application window has a main component.It is the parent of all other components that make up your app's GUI.
2.Every component, including the main component, has two important functions that you need to override: paint() and resized().
3.In the paint() function, you should add the code that will render the component on the screen.
4.You should implement a resized() function if you need special behaviour for your component, in order for it to react to size changes.
5.The paint() and resized() functions are callback functions that are called automatically when needed.You should never call them yourself.
6.You must not forget to set the size of the main component and to add it to the main window to make it visible.
*/