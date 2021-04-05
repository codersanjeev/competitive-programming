int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {
	if (A >= G || E >= C || B >= H || F >= D)
		return 0;
	int ux = max(A, E);
	int vx = min(C, G);
	int uy = max(B, F);
	int vy = min(D, H);
	return abs(vy - uy) * abs(vx - ux);
}
