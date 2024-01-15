void saveGame(int XX, int YY, vector<ii> Cache, int Xscore, int Oscore, string name1, string name2, string& nameFile, bool vsBot) {
	if (nameFile == "") {
		insertName:
		drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 2);
		if (!putname(XX - 18, YY + 2 * BOARD_SIZE - 1, nameFile)) {
			drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
			return;
		} if (nameFile == "") goto insertName;
	}

	bool checkSame = 0;
	for (string tmp : fileNames)
		if (tmp == nameFile) checkSame = 1;

	if (checkSame) {
		drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 3);
		while (true) {
			char key = _getch();
			if (key == 'N' || key == 'n') {
				drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
				nameFile = "";
				return;
			} else if (key == 'Y' || key == 'y') break;
		} 
	} else {
		while ((int)fileNames.size() >= 15)
			fileNames.erase(fileNames.begin());
		fileNames.push_back(nameFile);
	}
	
	drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
	drawName_Board(XX + 4 * BOARD_SIZE - 33, YY + 2 * BOARD_SIZE - 1, nameFile);
	pushList();

	ofstream File(nameFile + ".txt");
	File << int(vsBot) << " " << Xscore << " " << Oscore << '\n';
	File << name1 << " " << name2 << '\n';

	for (const auto& tmp : Cache) {
		File << tmp.first << " " << tmp.second << "\n";
	} File.close();
}