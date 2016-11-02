/*
==============================================================================

This file was auto-generated!

It contains the basic startup code for a Juce application.

==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"


//==============================================================================
class jucePractise03Application : public JUCEApplication
{
public:
	//==============================================================================
	jucePractise03Application() {}

	const String getApplicationName() override { return ProjectInfo::projectName; }
	const String getApplicationVersion() override { return ProjectInfo::versionString; }
	bool moreThanOneInstanceAllowed() override { return true; }

	//==============================================================================
	void initialise(const String& commandLine) override
	{
		// This method is where you should put your application's initialisation code..
		LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypefaceName(L"微软雅黑");
		mainWindow = new MainWindow(getApplicationName());
	}

	void shutdown() override
	{
		// Add your application's shutdown code here..

		mainWindow = nullptr; // (deletes our window)
	}

	//==============================================================================
	void systemRequestedQuit() override
	{
		// This is called when the app is being asked to quit: you can ignore this
		// request and let the app carry on running, or call quit() to allow the app to close.
		quit();
	}

	void anotherInstanceStarted(const String& commandLine) override
	{
		// When another instance of the app is launched while this one is running,
		// this method is invoked, and the commandLine parameter tells you what
		// the other instance's command-line arguments were.
	}

	//==============================================================================
	/*
	This class implements the desktop window that contains an instance of
	our MainContentComponent class.
	*/
	class MainWindow : public DocumentWindow
	{
	public:
		MainWindow(String name) : DocumentWindow(name,
			Colours::lightgrey,
			DocumentWindow::allButtons)
		{
			setUsingNativeTitleBar(false);
			setContentOwned(new MainContentComponent(), true);//在centreWithSize之前需要设置大小,参数2为true以此节点大小出现，为false以自身设置大小出现
			centreWithSize(getWidth(), getHeight());
			setVisible(true);
			setBackgroundColour(Colours::beige);//设置背景颜色
			setName(L"JUCEPractise03 Graphics");//设置名称
			setTitleBarHeight(40);//设置导航条高(按钮与标签会跟着变化)
			setResizable(true, true);//继承自ResizableWindow 参数1决定是否可变大小，参数2右下角是否可拖动来改变大小
			setResizeLimits(200, 200, 1000, 600);//设置最小拖动宽高，最大拖动宽高
		}

		void closeButtonPressed() override
		{
			// This is called when the user tries to close this window. Here, we'll just
			// ask the app to quit when this happens, but you can change this to do
			// whatever you need.
			JUCEApplication::getInstance()->systemRequestedQuit();
		}

		/* Note: Be careful if you override any DocumentWindow methods - the base
		class uses a lot of them, so by overriding you might break its functionality.
		It's best to do all your work in your content component instead, but if
		you really have to override any DocumentWindow methods, make sure your
		subclass also calls the superclass's method.
		*/

	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
	};

private:
	ScopedPointer<MainWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION(jucePractise03Application)
