function redstone() {
    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    let input = [];

    rl.on('line', (line) => {
        input.push(line.trim());
    });

    rl.on('close', () => {
        let index = 0;
        const t = parseInt(input[index++]);

        for (let test = 0; test < t; test++) {
            const n = parseInt(input[index++]);
            const gears = input[index++].split(' ').map(Number);

            const uniqueGears = new Set(gears);
            console.log(uniqueGears.size < gears.length ? "YES" : "NO");
        }
    });
}

redstone();
