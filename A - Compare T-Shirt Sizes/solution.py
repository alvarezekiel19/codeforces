def tshirt(a, b):
    if a[-1] != b[-1]:
        return ">" if a[-1] < b[-1] else "<"

    if a == b:
        return "="

    compare_size = len(a) < len(b)
    return "<" if compare_size ^ (a[-1] == "S") else ">"


def main():
    for _ in range(int(input())):
        print(tshirt(*input().split()))


if __name__ == "__main__":
    main()
