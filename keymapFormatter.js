const childProcess = require('node:child_process');
const path = require('node:path');
const fs = require('node:fs');

async function getQmkConfig() {
    return new Promise((resolve) => {
        childProcess.exec('qmk config', (_error, stdout, _stderr) => {
            const lines = stdout.split('\n');
            const userLines = lines.filter((line) => line.startsWith('user.'));
            const userObject = userLines.reduce((acc, line) => {
                const {groups: {key, value}} = line.match(/user\.(?<key>.*)=(?<value>.*)/);
                acc[key] = value;
                return acc;
            }, {})
            resolve(userObject);
        })
    });
}

async function main() {
    const {keyboard, keymap, qmk_home} = await getQmkConfig();
    const cPath = path.join(qmk_home, 'keyboards', keyboard, '../keymaps', keymap, 'keymap.c')
    const file = await fs.promises.readFile(cPath, 'utf8');
    const keymapStr = file.match(/const uint16_t PROGMEM keymaps\[]\[MATRIX_ROWS]\[MATRIX_COLS] = \{[\S\s]*?^};/m)[0]
    console.log(keymapStr);
}

main();

