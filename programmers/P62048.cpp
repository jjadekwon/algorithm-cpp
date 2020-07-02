int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long solution(int w, int h) {
    long long answer = 1;
    answer = (long long) w * h;
    answer -= w + h - gcd(w, h);
    return answer;
}