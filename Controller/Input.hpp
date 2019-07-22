#ifndef INPUT_HPP
# define INPUT_HPP

enum KeyState { pressed, held, released, not_held };

class Input
{
	private:
	static const int _maxKey = 283;
	KeyState _keyValues[_maxKey + 1];

	public:
	Input();
	Input(const Input & src);
	~Input();

	void takeInput(int key);
	void nextFrame();
	bool keyPressed(int key) const;
	bool keyDown(int key) const;
	bool keyReleased(int key) const;
	bool keyUp(int key) const;

	Input & operator=(const Input & src);
};

#endif
