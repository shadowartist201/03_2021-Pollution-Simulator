#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "residential.h"
using namespace std;

char residential::comm_statements(vector<string> thing, int vector_iter, int string_iter, int workers, int goods) {
	//when pulling up adjacent cells, check that they exist first
	string meanwhile, top_meanwhile, bottom_meanwhile;
	char middle_letter;
	bool left_ok = true;
	bool right_ok = true;
	bool top_ok = true;
	bool bottom_ok = true;
	meanwhile = thing.at(vector_iter); //string of char
	middle_letter = meanwhile.at(string_iter); //got the char
	if (vector_iter == 0) {
		top_ok = false;
	}
	if (vector_iter == thing.size() - 1) {
		bottom_ok = false;
	}
	if (string_iter == 0) {
		left_ok = false;
	}
	if (string_iter == meanwhile.length() - 1) {
		right_ok = false;
	}

	if (middle_letter == '1') {
		//do these things
		//check if thing is actually there
		//if adjacent to powerline
		int cells = 0;
		if (workers >= 1) {
			if (goods >= 1) {


				if (left_ok) {
					if (meanwhile.at(string_iter - 2) == 'T' || meanwhile.at(string_iter - 2) == '#') {
						//is adjacent to powerline on left
						workers--;
						goods--;
						cells++;
					}
					if (meanwhile.at(string_iter - 2) > 48 && meanwhile.at(string_iter - 2) < 58) {
						//if adjacent to 1, change to 1
						workers--;
						goods--;
						cells++;
					}
				}
				if (right_ok) {
					if (meanwhile.at(string_iter + 2) == 'T' || meanwhile.at(string_iter + 2) == '#') {
						//is adjacent to powerline on right
						workers--;
						goods--;
						cells++;
					}
					if (meanwhile.at(string_iter + 2) > 48 && meanwhile.at(string_iter + 2) < 58) {
						//if adjacent to 1, change to 1
						workers--;
						goods--;
						cells++;
					}
				}
				if (bottom_ok) {
					bottom_meanwhile = thing.at(vector_iter + 1);
					if (bottom_meanwhile.at(string_iter) == 'T' || bottom_meanwhile.at(string_iter) == '#') {
						//is adjacent to powerline on bottom
						workers--;
						goods--;
						cells++;
					}
					if (bottom_meanwhile.at(string_iter) > 48 && bottom_meanwhile.at(string_iter) < 58) {
						//if adjacent to 1, change to 1
						workers--;
						goods--;
						cells++;
					}
				}
				if (top_ok) {
					top_meanwhile = thing.at(vector_iter - 1);
					if (top_meanwhile.at(string_iter) == 'T' || top_meanwhile.at(string_iter) == '#') {
						//is adjacent to powerline on bottom
						workers--;
						goods--;
						cells++;
					}
					if (top_meanwhile.at(string_iter) > 48 && top_meanwhile.at(string_iter) < 58) {
						//if adjacent to 1, change to 1
						middle_letter = '1';
						workers--;
						goods--;
						cells++;
					}
				}
				if (bottom_ok && left_ok) {
					bottom_meanwhile = thing.at(vector_iter + 1);
					if (bottom_meanwhile.at(string_iter - 2) == 'T' || bottom_meanwhile.at(string_iter - 2) == '#') {
						//is adjacent to powerline on bottom left corner
						workers--;
						goods--;
						cells++;
					}
					if (bottom_meanwhile.at(string_iter - 2) > 48 && bottom_meanwhile.at(string_iter - 2) < 58) {
						//if adjacent to 1, change to 1
						workers--;
						goods--;
						cells++;
					}
				}
				if (bottom_ok && right_ok) {
					bottom_meanwhile = thing.at(vector_iter + 1);
					if (bottom_meanwhile.at(string_iter + 2) == 'T' || bottom_meanwhile.at(string_iter + 2) == '#') {
						//is adjacent to powerline on bottom right corner
						workers--;
						goods--;
						cells++;
					}
					if (bottom_meanwhile.at(string_iter + 2) > 48 && bottom_meanwhile.at(string_iter + 2) < 58) {
						//if adjacent to 1, change to 1
						workers--;
						goods--;
						cells++;
					}
				}
				if (top_ok && left_ok) {
					top_meanwhile = thing.at(vector_iter - 1);
					if (top_meanwhile.at(string_iter - 2) == 'T' || top_meanwhile.at(string_iter - 2) == '#') {
						//is adjacent to powerline on top left corner
						workers--;
						goods--;
						cells++;
					}
					if (top_meanwhile.at(string_iter - 2) > 48 && top_meanwhile.at(string_iter - 2) < 58) {
						//if adjacent to 1, change to 1
						workers--;
						goods--;
						cells++;
					}
				}
				if (top_ok && right_ok) {
					top_meanwhile = thing.at(vector_iter - 1);
					if (top_meanwhile.at(string_iter + 2) == 'T' || top_meanwhile.at(string_iter + 2) == '#') {
						//is adjacent to powerline on top right corner
						workers--;
						goods--;
						cells++;
					}
					if (top_meanwhile.at(string_iter + 2) > 48 && top_meanwhile.at(string_iter + 2) < 58) {
						//if adjacent to 1, change to 1
						workers--;
						goods--;
						cells++;
					}
				}
				if (cells >= 2) {
					//change middle number to 2
					middle_letter = '2';
				}
				//if adjacent to other thing
			}
		}
	}
	else if (middle_letter == 'C') //if population is 0
	{
		//do these things
		//check if thing is actually there
		//if adjacent to powerline
		if (workers >= 1) {
			if (goods >= 1) {

			
		if (left_ok) {
			if (meanwhile.at(string_iter - 2) == 'T' || meanwhile.at(string_iter - 2) == '#') {
				//is adjacent to powerline on left
				middle_letter = '1';
				workers--;
				goods--;
			}
			if (meanwhile.at(string_iter - 2) > 48 && meanwhile.at(string_iter - 2) < 58) {
				//if adjacent to 1, change to 1
				middle_letter = '1';
				workers--;
				goods--;
			}
		}
		if (right_ok) {
			if (meanwhile.at(string_iter + 2) == 'T' || meanwhile.at(string_iter + 2) == '#') {
				//is adjacent to powerline on right
				middle_letter = '1';
				workers--;
				goods--;
			}
			if (meanwhile.at(string_iter + 2) > 48 && meanwhile.at(string_iter + 2) < 58) {
				//if adjacent to 1, change to 1
				middle_letter = '1';
				workers--;
				goods--;
			}
		}
		if (bottom_ok) {
			bottom_meanwhile = thing.at(vector_iter + 1);
			if (bottom_meanwhile.at(string_iter) == 'T' || bottom_meanwhile.at(string_iter) == '#') {
				//is adjacent to powerline on bottom
				middle_letter = '1';
				workers--;
				goods--;
			}
			if (bottom_meanwhile.at(string_iter) > 48 && bottom_meanwhile.at(string_iter) < 58) {
				//if adjacent to 1, change to 1
				middle_letter = '1';
				workers--;
				goods--;
			}
		}
		if (top_ok) {
			top_meanwhile = thing.at(vector_iter - 1);
			if (top_meanwhile.at(string_iter) == 'T' || top_meanwhile.at(string_iter) == '#') {
				//is adjacent to powerline on bottom
				middle_letter = '1';
				workers--;
				goods--;
			}
			if (top_meanwhile.at(string_iter) > 48 && top_meanwhile.at(string_iter) < 58) {
				//if adjacent to 1, change to 1
				middle_letter = '1';
				workers--;
				goods--;
			}
		}
		if (bottom_ok && left_ok) {
			bottom_meanwhile = thing.at(vector_iter + 1);
			if (bottom_meanwhile.at(string_iter - 2) == 'T' || bottom_meanwhile.at(string_iter - 2) == '#') {
				//is adjacent to powerline on bottom left corner
				middle_letter = '1';
				workers--;
				goods--;
			}
			if (bottom_meanwhile.at(string_iter - 2) > 48 && bottom_meanwhile.at(string_iter - 2) < 58) {
				//if adjacent to 1, change to 1
				middle_letter = '1';
				workers--;
				goods--;
			}
		}
		if (bottom_ok && right_ok) {
			bottom_meanwhile = thing.at(vector_iter + 1);
			if (bottom_meanwhile.at(string_iter + 2) == 'T' || bottom_meanwhile.at(string_iter + 2) == '#') {
				//is adjacent to powerline on bottom right corner
				middle_letter = '1';
				workers--;
				goods--;
			}
			if (bottom_meanwhile.at(string_iter + 2) > 48 && bottom_meanwhile.at(string_iter + 2) < 58) {
				//if adjacent to 1, change to 1
				middle_letter = '1';
				workers--;
				goods--;
			}
		}
		if (top_ok && left_ok) {
			top_meanwhile = thing.at(vector_iter - 1);
			if (top_meanwhile.at(string_iter - 2) == 'T' || top_meanwhile.at(string_iter - 2) == '#') {
				//is adjacent to powerline on top left corner
				middle_letter = '1';
				workers--;
				goods--;
			}
			if (top_meanwhile.at(string_iter - 2) > 48 && top_meanwhile.at(string_iter - 2) < 58) {
				//if adjacent to 1, change to 1
				middle_letter = '1';
				workers--;
				goods--;
			}
		}
		if (top_ok && right_ok) {
			top_meanwhile = thing.at(vector_iter - 1);
			if (top_meanwhile.at(string_iter + 2) == 'T' || top_meanwhile.at(string_iter + 2) == '#') {
				//is adjacent to powerline on top right corner
				middle_letter = '1';
				workers--;
				goods--;
			}
			if (top_meanwhile.at(string_iter + 2) > 48 && top_meanwhile.at(string_iter + 2) < 58) {
				//if adjacent to 1, change to 1
				middle_letter = '1';
				workers--;
				goods--;
			}
		}
		//if adjacent to other thing
	}
}
		}
	return middle_letter;
}

char residential::res_statements(vector<string> thing, int vector_iter, int string_iter) {
	//when pulling up adjacent cells, check that they exist first
	string meanwhile, top_meanwhile, bottom_meanwhile;

	char middle_letter;
	bool left_ok = true;
	bool right_ok = true;
	bool top_ok = true;
	bool bottom_ok = true;
	meanwhile = thing.at(vector_iter); //string of char
	middle_letter = meanwhile.at(string_iter); //got the char
	if (vector_iter == 0) {
		top_ok = false;
	}
	if (vector_iter == thing.size() - 1) {
		bottom_ok = false;
	}
	if (string_iter == 0) {
		left_ok = false;
	}
	if (string_iter == meanwhile.length() - 1) {
		right_ok = false;
	}

	if (middle_letter == '4') {
		int cells = 0;//cell counter

		if (left_ok) {//check the left of the letter

			//if left position is at least 1 increase cells + 1
			if (meanwhile.at(string_iter - 2) >= 52 && meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (right_ok) {

			//if right position is at least 1 increase cells + 1
			if (meanwhile.at(string_iter + 2) >= 52 && meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (bottom_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom position is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter) >= 52 && bottom_meanwhile.at(string_iter) < 58)
				cells += 1;
		}

		if (top_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top position is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter) >= 52 && top_meanwhile.at(string_iter) < 58)
				cells += 1;
		}

		if (bottom_ok && left_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom left pos is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter - 2) >= 52 && bottom_meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (bottom_ok && right_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom right pos is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter + 2) >= 52 && bottom_meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (top_ok && left_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top left pos is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter - 2) >= 52 && top_meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (top_ok && right_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top right pos is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter + 2) >= 52 && top_meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (cells >= 8) {
			//change middle number to 2

			middle_letter = '5';
		}
	}
	else if (middle_letter == '3') {
		int cells = 0;//cell counter

		if (left_ok) {//check the left of the letter

			//if left position is at least 1 increase cells + 1
			if (meanwhile.at(string_iter - 2) >= 51 && meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (right_ok) {

			//if right position is at least 1 increase cells + 1
			if (meanwhile.at(string_iter + 2) >= 51 && meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (bottom_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom position is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter) >= 51 && bottom_meanwhile.at(string_iter) < 58)
				cells += 1;
		}

		if (top_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top position is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter) >= 51 && top_meanwhile.at(string_iter) < 58)
				cells += 1;
		}

		if (bottom_ok && left_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom left pos is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter - 2) >= 51 && bottom_meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (bottom_ok && right_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom right pos is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter + 2) >= 51 && bottom_meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (top_ok && left_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top left pos is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter - 2) >= 51 && top_meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (top_ok && right_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top right pos is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter + 2) >= 51 && top_meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (cells >= 6) {
			//change middle number to 2

			middle_letter = '4';
		}
	}
	else if (middle_letter == '2') {
		int cells = 0;//cell counter
		if (left_ok) {//check the left of the letter

			//if left position is at least 1 increase cells + 1
			if (meanwhile.at(string_iter - 2) >= 50 && meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (right_ok) {

			//if right position is at least 1 increase cells + 1
			if (meanwhile.at(string_iter + 2) >= 50 && meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (bottom_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom position is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter) >= 50 && bottom_meanwhile.at(string_iter) < 58)
				cells += 1;
		}

		if (top_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top position is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter) >= 50 && top_meanwhile.at(string_iter) < 58)
				cells += 1;
		}

		if (bottom_ok && left_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom left pos is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter - 2) >= 50 && bottom_meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (bottom_ok && right_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom right pos is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter + 2) >= 50 && bottom_meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (top_ok && left_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top left pos is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter - 2) >= 50 && top_meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (top_ok && right_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top right pos is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter + 2) >= 50 && top_meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (cells >= 4) {
			//change middle number to 2

			middle_letter = '3';
		}
	}
	else if (middle_letter == '1') {
		int cells = 0;//cell counter

		if (left_ok) {//check the left of the letter

			//if left position is at least 1 increase cells + 1
			if (meanwhile.at(string_iter - 2) >= 49 && meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (right_ok) {

			//if right position is at least 1 increase cells + 1
			if (meanwhile.at(string_iter + 2) >= 49 && meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (bottom_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom position is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter) >= 49 && bottom_meanwhile.at(string_iter) < 58)
				cells += 1;
		}

		if (top_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top position is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter) >= 49 && top_meanwhile.at(string_iter) < 58)
				cells += 1;
		}

		if (bottom_ok && left_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom left pos is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter - 2) >= 49 && bottom_meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (bottom_ok && right_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			//if bottom right pos is at least 1 increase cells + 1
			if (bottom_meanwhile.at(string_iter + 2) >= 49 && bottom_meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (top_ok && left_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top left pos is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter - 2) >= 49 && top_meanwhile.at(string_iter - 2) < 58)
				cells += 1;
		}

		if (top_ok && right_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			//if top right pos is at least 1 increase cells + 1
			if (top_meanwhile.at(string_iter + 2) >= 49 && top_meanwhile.at(string_iter + 2) < 58)
				cells += 1;
		}

		if (cells >= 2) {
			//change middle number to 2

			middle_letter = '2';
		}
	}
	else if (middle_letter == 'R') //if population is 0
	{
		//do these things
		//check if thing is actually there
		//if adjacent to powerline
		if (left_ok) {

			if (meanwhile.at(string_iter - 2) == 'T' || meanwhile.at(string_iter - 2) == '#') {
				//is adjacent to powerline on left

				middle_letter = '1';
			}
			if (meanwhile.at(string_iter - 2) > 48 && meanwhile.at(string_iter - 2) < 58) {
				//if adjacent to 1, change to 1

				middle_letter = '1';
			}

		}

		if (right_ok) {

			if (meanwhile.at(string_iter + 2) == 'T' || meanwhile.at(string_iter + 2) == '#') {
				//is adjacent to powerline on right

				middle_letter = '1';
			}
			if (meanwhile.at(string_iter + 2) > 48 && meanwhile.at(string_iter + 2) < 58) {
				//if adjacent to 1, change to 1

				middle_letter = '1';
			}
		}
		if (bottom_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			if (bottom_meanwhile.at(string_iter) == 'T' || bottom_meanwhile.at(string_iter) == '#') {
				//is adjacent to powerline on bottom

				middle_letter = '1';
			}
			if (bottom_meanwhile.at(string_iter) > 48 && bottom_meanwhile.at(string_iter) < 58) {
				//if adjacent to 1, change to 1

				middle_letter = '1';
			}
		}
		if (top_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			if (top_meanwhile.at(string_iter) == 'T' || top_meanwhile.at(string_iter) == '#') {
				//is adjacent to powerline on bottom
				middle_letter = '1';
			}
			if (top_meanwhile.at(string_iter) > 48 && top_meanwhile.at(string_iter) < 58) {
				//if adjacent to 1, change to 1

				middle_letter = '1';
			}
		}
		if (bottom_ok && left_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			if (bottom_meanwhile.at(string_iter - 2) == 'T' || bottom_meanwhile.at(string_iter - 2) == '#') {
				//is adjacent to powerline on bottom left corner
				middle_letter = '1';
			}
			if (bottom_meanwhile.at(string_iter - 2) > 48 && bottom_meanwhile.at(string_iter - 2) < 58) {
				//if adjacent to 1, change to 1

				middle_letter = '1';
			}
		}
		if (bottom_ok && right_ok) {

			bottom_meanwhile = thing.at(vector_iter + 1);
			if (bottom_meanwhile.at(string_iter + 2) == 'T' || bottom_meanwhile.at(string_iter + 2) == '#') {
				//is adjacent to powerline on bottom right corner
				middle_letter = '1';
			}
			if (bottom_meanwhile.at(string_iter + 2) > 48 && bottom_meanwhile.at(string_iter + 2) < 58) {
				//if adjacent to 1, change to 1

				middle_letter = '1';
			}
		}
		if (top_ok && left_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			if (top_meanwhile.at(string_iter - 2) == 'T' || top_meanwhile.at(string_iter - 2) == '#') {
				//is adjacent to powerline on top left corner
				middle_letter = '1';
			}
			if (top_meanwhile.at(string_iter - 2) > 48 && top_meanwhile.at(string_iter - 2) < 58) {
				//if adjacent to 1, change to 1

				middle_letter = '1';
			}
		}
		if (top_ok && right_ok) {

			top_meanwhile = thing.at(vector_iter - 1);
			if (top_meanwhile.at(string_iter + 2) == 'T' || top_meanwhile.at(string_iter + 2) == '#') {
				//is adjacent to powerline on top right corner
				middle_letter = '1';
			}
			if (top_meanwhile.at(string_iter + 2) > 48 && top_meanwhile.at(string_iter + 2) < 58) {
				//if adjacent to 1, change to 1

				middle_letter = '1';
			}
		}
		//if adjacent to other thing
	}

	////if time_step is not 1
	return middle_letter;
}

char residential::indus_statements(vector<string> thing, int vector_iter, int string_iter, int workers) {
	//when pulling up adjacent cells, check that they exist first
	string meanwhile, top_meanwhile, bottom_meanwhile;
	char middle_letter;
	bool left_ok = true;
	bool right_ok = true;
	bool top_ok = true;
	bool bottom_ok = true;
	meanwhile = thing.at(vector_iter); //string of char
	middle_letter = meanwhile.at(string_iter); //got the char
	if (vector_iter == 0) {
		top_ok = false;
	}
	if (vector_iter == thing.size() - 1) {
		bottom_ok = false;
	}
	if (string_iter == 0) {
		left_ok = false;
	}
	if (string_iter == meanwhile.length() - 1) {
		right_ok = false;
	}

	if (middle_letter == '2'){

		int cells = 0;//cell counter
		if (workers >= 2) {
			if (left_ok) {//check the left of the letter

				//if left position is at least 1 increase cells + 1
				if (meanwhile.at(string_iter - 2) >= 50 && meanwhile.at(string_iter - 2) < 58)
					cells += 1;
			}

			if (right_ok) {

				//if right position is at least 1 increase cells + 1
				if (meanwhile.at(string_iter + 2) >= 50 && meanwhile.at(string_iter + 2) < 58)
					cells += 1;
			}

			if (bottom_ok) {

				bottom_meanwhile = thing.at(vector_iter + 1);
				//if bottom position is at least 1 increase cells + 1
				if (bottom_meanwhile.at(string_iter) >= 50 && bottom_meanwhile.at(string_iter) < 58)
					cells += 1;
			}

			if (top_ok) {

				top_meanwhile = thing.at(vector_iter - 1);
				//if top position is at least 1 increase cells + 1
				if (top_meanwhile.at(string_iter) >= 50 && top_meanwhile.at(string_iter) < 58)
					cells += 1;
			}

			if (bottom_ok && left_ok) {

				bottom_meanwhile = thing.at(vector_iter + 1);
				//if bottom left pos is at least 1 increase cells + 1
				if (bottom_meanwhile.at(string_iter - 2) >= 50 && bottom_meanwhile.at(string_iter - 2) < 58)
					cells += 1;
			}

			if (bottom_ok && right_ok) {

				bottom_meanwhile = thing.at(vector_iter + 1);
				//if bottom right pos is at least 1 increase cells + 1
				if (bottom_meanwhile.at(string_iter + 2) >= 50 && bottom_meanwhile.at(string_iter + 2) < 58)
					cells += 1;
			}

			if (top_ok && left_ok) {

				top_meanwhile = thing.at(vector_iter - 1);
				//if top left pos is at least 1 increase cells + 1
				if (top_meanwhile.at(string_iter - 2) >= 50 && top_meanwhile.at(string_iter - 2) < 58)
					cells += 1;
			}

			if (top_ok && right_ok) {

				top_meanwhile = thing.at(vector_iter - 1);
				//if top right pos is at least 1 increase cells + 1
				if (top_meanwhile.at(string_iter + 2) >= 50 && top_meanwhile.at(string_iter + 2) < 58)
					cells += 1;
			}

			if (cells >= 4 && workers >= 2) {
				//change middle number to 2

				middle_letter = '3';
			}
		}
	}
	else if (middle_letter == '1') {

		int cells = 0;//cell counter
		if (workers >= 2) {


			if (left_ok) {//check the left of the letter

				//if left position is at least 1 increase cells + 1
				if (meanwhile.at(string_iter - 2) >= 49 && meanwhile.at(string_iter - 2) < 58)
					cells += 1;
			}

			if (right_ok) {

				//if right position is at least 1 increase cells + 1
				if (meanwhile.at(string_iter + 2) >= 49 && meanwhile.at(string_iter + 2) < 58)
					cells += 1;
			}

			if (bottom_ok) {

				bottom_meanwhile = thing.at(vector_iter + 1);
				//if bottom position is at least 1 increase cells + 1
				if (bottom_meanwhile.at(string_iter) >= 49 && bottom_meanwhile.at(string_iter) < 58)
					cells += 1;
			}

			if (top_ok) {

				top_meanwhile = thing.at(vector_iter - 1);
				//if top position is at least 1 increase cells + 1
				if (top_meanwhile.at(string_iter) >= 49 && top_meanwhile.at(string_iter) < 58)
					cells += 1;
			}

			if (bottom_ok && left_ok) {

				bottom_meanwhile = thing.at(vector_iter + 1);
				//if bottom left pos is at least 1 increase cells + 1
				if (bottom_meanwhile.at(string_iter - 2) >= 49 && bottom_meanwhile.at(string_iter - 2) < 58)
					cells += 1;
			}

			if (bottom_ok && right_ok) {

				bottom_meanwhile = thing.at(vector_iter + 1);
				//if bottom right pos is at least 1 increase cells + 1
				if (bottom_meanwhile.at(string_iter + 2) >= 49 && bottom_meanwhile.at(string_iter + 2) < 58)
					cells += 1;
			}

			if (top_ok && left_ok) {

				top_meanwhile = thing.at(vector_iter - 1);
				//if top left pos is at least 1 increase cells + 1
				if (top_meanwhile.at(string_iter - 2) >= 49 && top_meanwhile.at(string_iter - 2) < 58)
					cells += 1;
			}

			if (top_ok && right_ok) {

				top_meanwhile = thing.at(vector_iter - 1);
				//if top right pos is at least 1 increase cells + 1
				if (top_meanwhile.at(string_iter + 2) >= 49 && top_meanwhile.at(string_iter + 2) < 58)
					cells += 1;
			}

			if (cells >= 2 && workers >= 2) {
				//change middle number to 2
				middle_letter = '2';
			}

		}
	}
	else if (middle_letter == 'I') //if population is 0
	{

		//do these things
		//check if thing is actually there
		//if adjacent to powerline
		if (workers >= 2) {

			if (left_ok) {

				if (meanwhile.at(string_iter - 2) == 'T' || meanwhile.at(string_iter - 2) == '#') {
					//is adjacent to powerline on left

					middle_letter = '1';

					workers = workers - 2;
				}
				if (meanwhile.at(string_iter - 2) > 48 && meanwhile.at(string_iter - 2) < 58) {
					//if adjacent to 1, change to 1
					middle_letter = '1';
					workers = workers - 2;
				}

			}
			if (right_ok) {

				if (meanwhile.at(string_iter + 2) == 'T' || meanwhile.at(string_iter + 2) == '#') {
					//is adjacent to powerline on right
					middle_letter = '1';
					workers = workers - 2;
				}
				if (meanwhile.at(string_iter + 2) > 48 && meanwhile.at(string_iter + 2) < 58) {
					//if adjacent to 1, change to 1
					middle_letter = '1';
					workers = workers - 2;
				}

			}
			if (bottom_ok) {

				bottom_meanwhile = thing.at(vector_iter + 1);
				if (bottom_meanwhile.at(string_iter) == 'T' || bottom_meanwhile.at(string_iter) == '#') {
					//is adjacent to powerline on bottom

					middle_letter = '1';
					workers = workers - 2;
				}
				if (bottom_meanwhile.at(string_iter) > 48 && bottom_meanwhile.at(string_iter) < 58) {
					//if adjacent to 1, change to 1
					middle_letter = '1';
					workers = workers - 2;
				}
			}
			if (top_ok) {

				top_meanwhile = thing.at(vector_iter - 1);
				if (top_meanwhile.at(string_iter) == 'T' || top_meanwhile.at(string_iter) == '#') {
					//is adjacent to powerline on bottom

					middle_letter = '1';
					workers = workers - 2;
				}
				if (top_meanwhile.at(string_iter) > 48 && top_meanwhile.at(string_iter) < 58) {
					//if adjacent to 1, change to 1
					middle_letter = '1';
					workers = workers - 2;
				}
			}
			if (bottom_ok && left_ok) {

				bottom_meanwhile = thing.at(vector_iter + 1);
				if (bottom_meanwhile.at(string_iter - 2) == 'T' || bottom_meanwhile.at(string_iter - 2) == '#') {
					//is adjacent to powerline on bottom left corner

					middle_letter = '1';
					workers = workers - 2;
				}
				if (bottom_meanwhile.at(string_iter - 2) > 48 && bottom_meanwhile.at(string_iter - 2) < 58) {
					//if adjacent to 1, change to 1
					middle_letter = '1';
					workers = workers - 2;
				}
			}
			if (bottom_ok && right_ok) {

				bottom_meanwhile = thing.at(vector_iter + 1);
				if (bottom_meanwhile.at(string_iter + 2) == 'T' || bottom_meanwhile.at(string_iter + 2) == '#') {
					//is adjacent to powerline on bottom right corner

					middle_letter = '1';
					workers = workers - 2;
				}
				if (bottom_meanwhile.at(string_iter + 2) > 48 && bottom_meanwhile.at(string_iter + 2) < 58) {
					//if adjacent to 1, change to 1
					middle_letter = '1';
					workers = workers - 2;
				}
			}
			if (top_ok && left_ok) {

				top_meanwhile = thing.at(vector_iter - 1);
				if (top_meanwhile.at(string_iter - 2) == 'T' || top_meanwhile.at(string_iter - 2) == '#') {
					//is adjacent to powerline on top left corner

					middle_letter = '1';
					workers = workers - 2;
				}
				if (top_meanwhile.at(string_iter - 2) > 48 && top_meanwhile.at(string_iter - 2) < 58) {
					//if adjacent to 1, change to 1
					middle_letter = '1';
					workers = workers - 2;
				}
			}
			if (top_ok && right_ok) {

				top_meanwhile = thing.at(vector_iter - 1);
				if (top_meanwhile.at(string_iter + 2) == 'T' || top_meanwhile.at(string_iter + 2) == '#') {
					//is adjacent to powerline on top right corner

					middle_letter = '1';
					workers = workers - 2;
				}
				if (top_meanwhile.at(string_iter + 2) > 48 && top_meanwhile.at(string_iter + 2) < 58) {
					//if adjacent to 1, change to 1
					middle_letter = '1';
					workers = workers - 2;
				}
			}
		}
		//if adjacent to other thing
	}

	return middle_letter;
}

char residential::poll_statements(vector<string> thing, int vector_iter, int string_iter) {
	string meanwhile, top_meanwhile, bottom_meanwhile;

	char middle_letter;
	bool left_ok = true;
	bool right_ok = true;
	bool top_ok = true;
	bool bottom_ok = true;
	meanwhile = thing.at(vector_iter); //string of char
	middle_letter = meanwhile.at(string_iter); //got the char
	if (vector_iter == 0) {
		top_ok = false;
	}
	if (vector_iter == thing.size() - 1) {
		bottom_ok = false;
	}
	if (string_iter == 0) {
		left_ok = false;
	}
	if (string_iter == meanwhile.length() - 2) {
		right_ok = false;
	}

	if (middle_letter == '1') {

	if (left_ok) {
		if (meanwhile.at(string_iter - 2) == 51) {
			//if 1 is adjacent to 3, change to 2
			middle_letter = '2';
		}
	}
	if (right_ok) {
		if (meanwhile.at(string_iter + 2) == 51) {
			//if 1 is adjacent to 3, change to 2
			middle_letter = '2';
		}
	}
	if (bottom_ok) {
		bottom_meanwhile = thing.at(vector_iter + 1);
		if (bottom_meanwhile.at(string_iter) == 51) {
			//if 1 is adjacent to 3, change to 2
			middle_letter = '2';
		}
	}
	if (top_ok) {
		top_meanwhile = thing.at(vector_iter - 1);
		if (top_meanwhile.at(string_iter) == 51) {
			//if 1 is adjacent to 3, change to 2
			middle_letter = '2';
		}
	}
	if (bottom_ok && left_ok) {
		bottom_meanwhile = thing.at(vector_iter + 1);
		if (bottom_meanwhile.at(string_iter - 2) == 51) {
			//if 1 is adjacent to 3, change to 2
			middle_letter = '2';
		}
	}
	if (bottom_ok && right_ok) {
		bottom_meanwhile = thing.at(vector_iter + 1);
		if (bottom_meanwhile.at(string_iter + 2) == 51) {
			//if 1 is adjacent to 3, change to 2
			middle_letter = '2';
		}
	}
	if (top_ok && left_ok) {
		top_meanwhile = thing.at(vector_iter - 1);
		if (top_meanwhile.at(string_iter - 2) == 51) {
			//if 1 is adjacent to 3, change to 2
			middle_letter = '2';
		}
	}
	if (top_ok && right_ok) {
		top_meanwhile = thing.at(vector_iter - 1);
		if (top_meanwhile.at(string_iter + 2) == 51) {
			//if 1 is adjacent to 3, change to 2
			middle_letter = '2';
		}
	}
	}
	else if (middle_letter == '0') //if population is 0
	{

		//do these things
		//check if thing is actually there

		if (left_ok) {

			if (meanwhile.at(string_iter - 2) == 50) {
				//if 0 is adjacent to 2, change to 1
				middle_letter = '1';
			}
			if (meanwhile.at(string_iter - 2) == 51) {
				//if 0 is adjacent to 3, change to 2
				middle_letter = '2';
			}

		}
		if (right_ok) {
			if (meanwhile.at(string_iter + 2) == 50) {
				//if 0 is adjacent to 2, change to 1
				middle_letter = '1';
			}
			if (meanwhile.at(string_iter + 2) == 51) {
				//if 0 is adjacent to 3, change to 2
				middle_letter = '2';
			}
		}
		if (bottom_ok) {
			bottom_meanwhile = thing.at(vector_iter + 1);
			if (bottom_meanwhile.at(string_iter) == 50) {
				//if 0 is adjacent to 2, change to 1
				middle_letter = '1';
			}
			if (bottom_meanwhile.at(string_iter) == 51) {
				//if 0 is adjacent to 3, change to 2
				middle_letter = '2';
			}
		}
		if (top_ok) {
			top_meanwhile = thing.at(vector_iter - 1);
			if (top_meanwhile.at(string_iter) == 50) {
				//if 0 is adjacent to 2, change to 1
				middle_letter = '1';
			}
			if (top_meanwhile.at(string_iter) == 51) {
				//if 0 is adjacent to 3, change to 2
				middle_letter = '2';
			}
		}
		if (bottom_ok && left_ok) {
			bottom_meanwhile = thing.at(vector_iter + 1);
			if (bottom_meanwhile.at(string_iter - 2) == 50) {
				//if 0 is adjacent to 2, change to 1
				middle_letter = '1';
			}
			if (bottom_meanwhile.at(string_iter - 2) == 51) {
				//if 0 is adjacent to 3, change to 2
				middle_letter = '2';
			}
		}
		if (bottom_ok && right_ok) {
			bottom_meanwhile = thing.at(vector_iter + 1);
			if (bottom_meanwhile.at(string_iter + 2) == 50) {
				//if 0 is adjacent to 2, change to 1
				middle_letter = '1';
			}
			if (bottom_meanwhile.at(string_iter + 2) == 51) {
				//if 0 is adjacent to 3, change to 2
				middle_letter = '2';
			}
		}
		if (top_ok && left_ok) {
			top_meanwhile = thing.at(vector_iter - 1);
			if (top_meanwhile.at(string_iter - 2) == 50) {
				//if 0 is adjacent to 2, change to 1
				middle_letter = '1';
			}
			if (top_meanwhile.at(string_iter - 2) == 51) {
				//if 0 is adjacent to 3, change to 2
				middle_letter = '2';
			}
		}
		if (top_ok && right_ok) {
			top_meanwhile = thing.at(vector_iter - 1);
			if (top_meanwhile.at(string_iter + 2) == 50) {
				//if 0 is adjacent to 2, change to 1
				middle_letter = '1';
			}
			if (top_meanwhile.at(string_iter + 2) == 51) {
				//if 0 is adjacent to 3, change to 2
				middle_letter = '2';
			}
		}
	}
	return middle_letter;
	
}


vector<string> residential::copy_paste(vector<string> input) {
	vector<string> otherone;
	int num = 0;
	while (input.begin() + num < input.end()) {
		otherone.push_back(input.at(num));
		num++;
	}
	return otherone;
}

vector<string> residential::main(vector<string> input, int num1, int num3) {
	vector<string> storage;
	vector<string> backup;
	vector<string> interim_vector;
	vector<string> pollution; //based on final state
	int time_limit = num1;
	int refresh_rate = num3;
	int time_step = 1;
	int num = 0;
	int num2 = 0;
	int workers = 0;
	int indus_workers = 0;
	int res_workers = 0;
	int comm_workers = 0;
	int interim_workers = 0;
	int interim_goods = 0;
	int indus_goods = 0;
	int	comm_goods = 0;
	int goods = 0;
	int res_total = 0;
	int indus_total = 0;
	int comm_total = 0;
	string interim;
	string comparison;
	string interim_char_string;
	char interim_char = '0';
	storage = input;

	backup = copy_paste(storage); //make a backup of the initial state


	//do a loop starting at a time_step variable and increase by refresh_rate until time_limit is reached
	//make if statement to ignore '-' (roads), 'T' (powerlines), '#' (other powerlines), 'P' (power plants), and ' ' (empty space)
	//the only acceptable input remaining should be 'R', 'I', and 'C' (our zones)
	//make halt condition
	//make if statements specific to 'R', 'I', or 'C'
	//when pulling up adjacent cells, check that they exist first

	while (time_step < time_limit + 1) {
		interim_vector = copy_paste(storage);
		interim_workers = workers;
		interim_goods = goods;
		comm_goods = 0;
		res_workers = 0;
		indus_workers = 0;
		indus_goods = 0;
		while (interim_vector.begin() + num < interim_vector.end()) { //iterate through the vector
			interim = storage.at(num);
			//interim.push_back(' '); //add a char at the end to get rid of out of bounds error
			num2 = 0;

			while (num2 < interim.length()) { //iterate through the strings
				if (((interim.at(num2) == '-' || interim.at(num2) == 'T') || (interim.at(num2) == '#' || interim.at(num2) == 'P')) || interim.at(num2) == ' ') {
					//do nothing
				}
				else {
					comparison = backup.at(num); //compare char with backup vector and determine category
					if (comparison.at(num2) == 'C') {
						//commercial function

						interim_char = comm_statements(storage, num, num2, workers, interim_goods);
						if (interim.at(num2) != interim_char) {
							comm_workers--;
							comm_goods--;
							interim_goods--;
							comm_total++;
						}
					}
					if (comparison.at(num2) == 'R') {
						//residential function
						interim_char = res_statements(storage, num, num2);

						if (interim.at(num2) != interim_char) {

							res_workers++;
							res_total++;
						}
					}
					if (comparison.at(num2) == 'I') {
						//industrial function
						interim_char = indus_statements(storage, num, num2, interim_workers);
						if (interim.at(num2) != interim_char) {

							interim_workers = interim_workers - 2;
							indus_workers = indus_workers - 2;

							indus_goods++;
							indus_total++;

						}
					}
					//put char coordinates (num, num2) into categorial function along with vector
					//take returned char and replace old char in vector
					interim_char_string = interim_char; //because the replace function wonn't take chars >_<

					interim.replace(num2, 1, interim_char_string);

					interim_vector.at(num) = interim; //put new string in vector
				}
				num2 = num2 + 2;
			}
			num++;
		}
		//output the vector
		if (storage == interim_vector) { //if the vector doesn't change
			cout << "Time Step: " << time_step << endl;

			cout << "Available Workers " << workers << " Available Goods " << goods << endl;

			if (refresh_rate % 2 == 0) { //if refresh_rate is even
				if (time_step % refresh_rate == 1) { //print odd steps
					int vectornum = 0; //vector iterator
					int num3 = 0; //normal iterator

					while (num3 < interim.length() + 3) { //output a line of --- as long as the string + 2
						cout << "-";
						num3++;
					}
					cout << endl;

					while (storage.begin() + vectornum < storage.end()) { //for the duration of the vector
						interim = storage.at(vectornum); //grab a string
						cout << "|" << interim << " |" << endl; //print it with walls
						vectornum = vectornum + 1; //move to next vector iterator
					}
					num3 = 0; //reset normal iterator to 0

					while (num3 < interim.length() + 3) { //output a line of --- as long as the string + 2
						cout << "-";
						num3++;
					}
					cout << endl;
					cout << endl;
				}
				else {
					cout << endl;
				}
			}
			else { //refresh_rate is odd
				if (time_step % refresh_rate == 0) { //print even steps
					int vectornum = 0; //vector iterator
					int num3 = 0; //normal iterator

					while (num3 < interim.length() + 3) { //output a line of --- as long as the string + 2
						cout << "-";
						num3++;
					}
					cout << endl;

					while (storage.begin() + vectornum < storage.end()) { //for the duration of the vector
						interim = storage.at(vectornum); //grab a string
						cout << "|" << interim << " |" << endl; //print it with walls
						vectornum = vectornum + 1; //move to next vector iterator
					}
					num3 = 0; //reset normal iterator to 0

					while (num3 < interim.length() + 3) { //output a line of --- as long as the string + 2
						cout << "-";
						num3++;
					}
					cout << endl;
					cout << endl;
				}
				else {
					cout << endl;
				}
			}
			num = 0;
			num2 = 0;
			break;
		}
		else {
			storage = copy_paste(interim_vector);

			workers = indus_workers + comm_workers + res_workers + workers;

			goods = indus_goods + comm_goods + goods;


			cout << "Time Step: " << time_step << endl;

			cout << "Available Workers " << workers << " Available Goods " << goods << endl;

			if (refresh_rate % 2 == 0) { //if refresh_rate is even
				if (time_step % refresh_rate == 1) { //print odd steps
					int vectornum = 0; //vector iterator
					int num3 = 0; //normal iterator

					while (num3 < interim.length() + 2) { //output a line of --- as long as the string + 2
						cout << "-";
						num3++;
					}
					cout << endl;

					while (storage.begin() + vectornum < storage.end()) { //for the duration of the vector
						interim = storage.at(vectornum); //grab a string
						cout << "|" << interim << " |" << endl; //print it with walls
						vectornum = vectornum + 1; //move to next vector iterator
					}
					num3 = 0; //reset normal iterator to 0

					while (num3 < interim.length() + 2) { //output a line of --- as long as the string + 2
						cout << "-";
						num3++;
					}
					cout << endl;
					cout << endl;
				}
				else {
					cout << endl;
				}
			}
			else { //refresh_rate is odd
				if (time_step % refresh_rate == 0) { //print even steps
					int vectornum = 0; //vector iterator
					int num3 = 0; //normal iterator

					while (num3 < interim.length() + 2) { //output a line of --- as long as the string + 2
						cout << "-";
						num3++;
					}
					cout << endl;

					while (storage.begin() + vectornum < storage.end()) { //for the duration of the vector
						interim = storage.at(vectornum); //grab a string
						cout << "|" << interim << " |" << endl; //print it with walls
						vectornum = vectornum + 1; //move to next vector iterator
					}
					num3 = 0; //reset normal iterator to 0

					while (num3 < interim.length() + 2) { //output a line of --- as long as the string + 2
						cout << "-";
						num3++;
					}
					cout << endl;
					cout << endl;
				}
				else {
					cout << endl;
				}
			}
			num = 0;
			num2 = 0;

			//time_step = time_step + refresh_rate;
			time_step++;
		}
	}
	cout << endl;
	cout << "Final Region State" << endl;

			int vectornum = 0; //vector iterator
			num3 = 0; //normal iterator
			

			while (num3 < interim.length() + 3) { //output a line of --- as long as the string + 2
				cout << "-";
				num3++;
			}
			cout << endl;

			while (storage.begin() + vectornum < storage.end()) { //for the duration of the vector
				interim = storage.at(vectornum); //grab a string
				cout << "|" << interim << " |" << endl; //print it with walls
				vectornum = vectornum + 1; //move to next vector iterator
			}
			num3 = 0; //reset normal iterator to 0

			while (num3 < interim.length() + 3) { //output a line of --- as long as the string + 2
				cout << "-";
				num3++;
			}
			cout << endl;
			cout << endl;
		

	//pollution

	pollution = storage;
	int poll_total = 0;

	num = 0;
	while (pollution.begin() + num < pollution.end()) { //iterate through the vector
		interim = pollution.at(num);
		interim.push_back(' ');
		num2 = 0;

		while (interim.begin() + num2 < interim.end() - 1) {

			comparison = backup.at(num);
			if (comparison.at(num2) != 'I') {
				interim.replace(num2, 1, "0");
			}
			if (interim.at(num2) == 'I') {
				interim.replace(num2, 1, "0");
			}
			num2 = num2 + 2;
		}
		pollution.at(num) = interim;
		num++;
	}
	num = 0;

	while (pollution.begin() + num < pollution.end()) { //iterate through the vector

		interim = pollution.at(num);
		num2 = 0;

		while (interim.begin() + num2 < interim.end() - 1) {

			interim_char = poll_statements(pollution, num, num2);
			if (interim_char != interim.at(num2)) {
				poll_total++;
			}
			interim_char_string = interim_char; //because the replace function wonn't take chars >_<

			interim.replace(num2, 1, interim_char_string);
			num2 = num2 + 2;

		}

		pollution.at(num) = interim; //put new string in vector

		num++;
	}

	vectornum = 0; //vector iterator
	num3 = 0; //normal iterator

	cout << "Pollution" << endl;

	while (num3 < interim.length() + 2) { //output a line of --- as long as the string + 2
		cout << "-";
		num3++;
	}
	cout << endl;

	while (pollution.begin() + vectornum < pollution.end()) { //for the duration of the vector
		interim = pollution.at(vectornum); //grab a string
		interim.erase(interim.length() - 1);
		cout << "|" << interim << " |" << endl; //print it with walls
		vectornum = vectornum + 1; //move to next vector iterator
	}
	num3 = 0; //reset normal iterator to 0

	while (num3 < interim.length() + 3) { //output a line of --- as long as the string + 2
		cout << "-";
		num3++;
	}
	cout << endl << endl;
	
	cout << "The total populations for the regions are:" << endl;
	cout << "Residential: " << res_total << endl;
	cout << "Industrial: " << indus_total << endl;
	cout << "Commercial: " << comm_total << endl;
	cout << "The total amount of pollution in the region is " << indus_total + poll_total << " units." << endl;
	cout << "Please enter the diagonal corners of the area you wish to have more information about. (MinX = 0, MinY = 0, MaxX = " << storage.at(0).length() / 2 << ", MaxY = " << storage.size() - 1 << ")" << endl;
	cout << "X1:" << endl;
	cout << "Y1:" << endl;
	cout << "X2:" << endl;
	cout << "Y2:" << endl;
	cout << "The total populations for the requested area are:" << endl;
	cout << "Residential: " << endl;
	cout << "Industrial: " << endl;
	cout << "Commercial: " << endl;
	cout << "The total amount of pollution for the requested area is " << " units." << endl;
	cout << "Simulation complete" << endl;


	return storage;
}
