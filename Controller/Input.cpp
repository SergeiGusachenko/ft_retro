#include "Input.hpp"

Input::Input()
{
	for (int i = 0; i < Input::_maxKey; i++)
		this->_keyValues[i] = not_held;
}

Input::Input(const Input & src)
{
	for (int i = 0; i < Input::_maxKey; i++)
		this->_keyValues[i] = src._keyValues[i];
}

Input::~Input() {}

void Input::takeInput(int key)
{
	if (key < 0 || key >= Input::_maxKey)
		return;
	if (this->_keyValues[key] == not_held)
		this->_keyValues[key] = pressed;
	else if (this->_keyValues[key] == released)
		this->_keyValues[key] = held;
}

// call keyPressed, keyDown, etc. before calling this
void Input::nextFrame()
{
	for (int key = 0; key < Input::_maxKey; key++)
	{
		switch(this->_keyValues[key])
		{
		case pressed:
		case held:
			this->_keyValues[key] = released;
			break;
		case released:
			this->_keyValues[key] = not_held;
		default:
			break;
		}
	}
}

bool Input::keyPressed(int key) const
{
	return this->_keyValues[key] == pressed;
}

bool Input::keyDown(int key) const
{
	return this->_keyValues[key] == pressed ||
			this->_keyValues[key] == held;
}

bool Input::keyReleased(int key) const
{
	return this->_keyValues[key] == released;
}

bool Input::keyUp(int key) const
{
	return this->_keyValues[key] == released ||
			this->_keyValues[key] == not_held;
}

Input & Input::operator=(const Input & src)
{
	for (int i = 0; i < Input::_maxKey; i++)
		this->_keyValues[i] = src._keyValues[i];
	return *this;
}
