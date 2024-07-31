let fullName = 'Escobar, Pablo';
let [a] = fullName.matchAll(/(\w+), (\w+)/g);
console.log(a[1]);