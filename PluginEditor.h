/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
/* GUI Component */
class DriveDesign : public LookAndFeel_V4
{
public:
    DriveDesign()
    {
        setColour(Slider::rotarySliderOutlineColourId, Colours::silver);
        setColour(Slider::rotarySliderFillColourId, Colours::darkred);
        setColour(Slider::thumbColourId, Colours::whitesmoke);
    }
};

class RangeDesign : public LookAndFeel_V4
{
public:
    RangeDesign()
    {
        setColour(Slider::rotarySliderOutlineColourId, Colours::silver);
        setColour(Slider::rotarySliderFillColourId, Colours::royalblue);
        setColour(Slider::thumbColourId, Colours::whitesmoke);
    }
};

class BlendDesign : public LookAndFeel_V4
{
public:
    BlendDesign()
    {
        setColour(Slider::rotarySliderOutlineColourId, Colours::silver);
        setColour(Slider::rotarySliderFillColourId, Colours::purple);
        setColour(Slider::thumbColourId, Colours::whitesmoke);
    }
};

class VolumeDesign : public LookAndFeel_V4
{
public:
    VolumeDesign()
    {
        setColour(Slider::rotarySliderOutlineColourId, Colours::silver);
        setColour(Slider::rotarySliderFillColourId, Colours::darkgreen);
        setColour(Slider::thumbColourId, Colours::whitesmoke);
    }
};

/* AudioProcessor Component */
class VirtualAmpAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    VirtualAmpAudioProcessorEditor (VirtualAmpAudioProcessor&);
    ~VirtualAmpAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    
    /* Pointers to Sliders represent each knob in GUI.
     * ScopedPointers are pointers that are deallocated once the pointer exits scope.
     * Memory management is extremely important in audio processing as sound files
     * create audio callbacks called every 41.4kHz, audio callbacks need to be produced
     * to provide audio buffers on time (otherwise you get annoying buzzes)
     */
    ScopedPointer<Slider> driveSlider;
    ScopedPointer<Slider> rangeSlider;
    ScopedPointer<Slider> blendSlider;
    ScopedPointer<Slider> volSlider;
    
    /* ValueTreeStates store parameter values, can save, store, and manage presets,
     * allow these to be shared between classes
     */
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volAttachment;
    
    /* GUI Components */
    DriveDesign paintDrive;
    RangeDesign paintRange;
    BlendDesign paintBlend;
    VolumeDesign paintVolume;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VirtualAmpAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VirtualAmpAudioProcessorEditor)
};
