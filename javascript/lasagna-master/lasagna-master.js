/// <reference path="./global.d.ts" />
// @ts-check

/**
 * Implement the functions needed to solve the exercise here.
 * Do not forget to export them so they are available for the
 * tests. Here an example of the syntax as reminder:
 *
 * export function yourFunction(...) {
 *   ...
 * }
 */

/**
 * If the timer shows 0, it should return 'Lasagna is done.'.
    If the timer shows any other number, the result should be 'Not done, please wait.'.
    If the function is called without a timer value, the result should be 'You forgot to set the timer.'.
    @param {number} remainingTime
    @return {string} State of the lasagna
 */
export function cookingStatus(remainingTime) {
    switch (remainingTime) {
        case undefined:
            return 'You forgot to set the timer.';
        case 0:
            return 'Lasagna is done.';
        default:
            return 'Not done, please wait.';
    }
}

export function preparationTime(layers, avgTime) {
    if (avgTime === undefined)
        avgTime = 2;
    return avgTime * layers.length;
}

/**
 * 
 * @param {Array<string>} layers 
 * @return {Record<string, number>}
 */
export function quantities(layers) {
    const noodleValue = 50;
    const sauceValue = 0.2;
    let noodleCount = layers.filter(f => f === 'noodles').length;
    let sauceCount = layers.filter(f => f === 'sauce').length;
    return {
        noodles: noodleCount * noodleValue,
        sauce: sauceCount * sauceValue
    };
}

/**
 * @param {Array<string>} friendsList
 * @param {Array<string>} myList
 * @return {undefined}
 */
export function addSecretIngredient(friendsList, myList) {
    myList.push(friendsList[friendsList.length - 1]);
}

/**
 * @param {Record<string, number} recipe
 * @param {number} portions
 * @return {Record<string, number>}
 */
export function scaleRecipe(recipe, portions) {
    let obj = {}
    for (let prop in recipe) {
        obj[prop] = recipe[prop] * portions / 2;
    }

    // @ts-ignore
    return obj;
}