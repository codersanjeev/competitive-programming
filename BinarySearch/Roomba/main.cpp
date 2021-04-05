bool solve(vector<string> &moves, int x, int y) {
	int cx = 0, cy = 0;
	for (const auto &move : moves) {
		if (move == "NORTH") {
			cy++;
		} else if (move == "SOUTH") {
			cy--;
		} else if (move == "EAST") {
			cx++;
		} else {
			cx--;
		}
	}
	return cx == x && cy == y;
}