#include <iostream>
#include <vector>

using namespace std;

struct Robot {
	int x;
	int y;
	string direction;

	Robot(int x, int y, string direction) {
		this->x = x;
		this->y = y_;
		this->direction = direction;
	}

	void move_forward()
	{
		if (direction == "Up") {
			x--;
		}
		else if (direction == "Right") {
			y++;
		}
		else if (direction == "Down") {
			x++;
		}
		else if (direction == "Left") {
			y--;
		}
	}

	void rotate_right() {
		if (direction == "Up") {
			direction = "Right";
		}
		else if (direction == "Right") {
			direction = "Down";
		}
		else if (direction == "Down") {
			direction = "Left";
		}
		else if (direction == "Left") {
			direction = "Up";
		}
	}

	void rotate_left() {
		if (direction == "Up") {
			direction = "Left";
		}
		else if (direction == "Right") {
			direction = "Up";
		}
		else if (direction == "Down") {
			direction = "Right";
		}
		else if (direction == "Left") {
			direction = "Down";
		}
	}
  
  void print(vector <vector <char>>& space)
  {
    for (int i = 0; i < space.size(); i++) {
      for (int j = 0; j < space.size(); j++) {
        cout << ar[i][j] << " ";
      }
      cout << "\n";
    }
  }
};

int main()
{
	int n;
	cin >> n;
	vector <vector <char>> space(n, vector <char> (n, '.'));

	Robot robot(0, 0, "Up");
	space[robot.x][robot.y] = '#';
}
