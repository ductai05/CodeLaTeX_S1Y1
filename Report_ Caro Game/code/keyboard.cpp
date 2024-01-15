int nextMove() {  
	while (true) {
		if (_kbhit()) {
			char c = _getch();

			if (c == 13 || c == ' ') return 0;
			if (c == 27) return 5;

			if (c == -32) {
				c = _getch();

				if (c == 72) return 1;
				if (c == 75) return 2;
				if (c == 80) return 3;
				if (c == 77) return 4;
			}

			if (c == 'W' || c == 'w') return 1;
			if (c == 'A' || c == 'a') return 2;
			if (c == 'S' || c == 's') return 3;
			if (c == 'D' || c == 'd') return 4;

			if (c == 'U' || c == 'u') return 6;
			if (c == 'I' || c == 'i') return 7;
		}
	}
}