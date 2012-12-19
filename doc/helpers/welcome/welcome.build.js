/**
 *  Welcome Builder
 *  ===============
 *  This node application is used to render the last items of the changelog into the welcome.html file.
 */

var fs = require('fs');

var main_template = fs.readFileSync('welcome.template.html', 'utf8'),
    element_template = fs.readFileSync('changelog-item.html', 'utf8'),
    changelog = JSON.parse(fs.readFileSync('../../source/changelog.json', 'utf8'));

changelog.reverse();

var html = '',
    cnt = 0,
    max = 2;

while(cnt < max){
    html += element_template.replace(/\{\{message\}\}/gm, changelog[cnt].message).replace(/\{\{date\}\}/gm, changelog[cnt].date);
    cnt++;
}


fs.writeFileSync('../../source/welcome.html', main_template.replace(/\{\{changelog\}\}/gm, html));

console.log('done');