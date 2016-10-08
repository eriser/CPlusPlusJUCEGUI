/*
  ==============================================================================

    test.h
    Created: 18 Aug 2016 1:30:38pm
    Author:  zhoukb

  ==============================================================================
*/

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class test    : public Component
{
public:
    test();
    ~test();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (test)
};


#endif  // TEST_H_INCLUDED
