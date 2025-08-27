import sys


def main():
    input = sys.stdin.readline

    n, m = map(int, input().split())
    a = list(map(int, input().split()))

    distinct = [0] * n
    seen = set()

    for i in range(n - 1, -1, -1):
        seen.add(a[i])
        distinct[i] = len(seen)

    for _ in range(m):
        lucs = int(input())
        print(distinct[lucs - 1])


if __name__ == "__main__":
    main()
