/**
 * Wrap the text into specified html tag.
 * 
 * @param {string} text Text to be wrapped
 * @param {string} tag Tag to wrap around the text
 * @returns 
 */
function wrap(text, tag) {
  return `<${tag}>${text}</${tag}>`;
}

/**
 * Replace the delimiter around a text with specified html tag.
 * 
 * @param {string} markdown Text, with delimiter on start and end
 * @param {string} delimiter Delimiter
 * @param {string} tag Tag to convert to
 * @returns 
 */
function parser(markdown, delimiter, tag) {
  const pattern = new RegExp(`${delimiter}(.+)${delimiter}`);
  const replacement = `<${tag}>$1</${tag}>`;
  return markdown.replace(pattern, replacement);
}

function parseStrong(markdown) {
  return parser(markdown, '__', 'strong');
}

function parseEm(markdown) {
  return parser(markdown, '_', 'em');
}

function parseAccents(markdown) {
  let parsedStrong = parseStrong(markdown);
  let parsedEm = parseEm(parsedStrong);
  return parsedEm;
}

function parseText(markdown) {
  const parsedText = parseAccents(markdown);
  if (list) {
    return parsedText;
  } else {
    return wrap(parsedText, 'p');
  }
}

function parseHeader(markdown) {
  let count = 0;
  for (let i = 0; i < markdown.length; i++) {
    if (markdown[i] === '#') {
      count += 1;
    } else {
      break;
    }
  }
  if (count === 0 || count > 6) {
    return null;
  }
  const headerTag = `h${count}`;
  const headerHtml = wrap(markdown.substring(count + 1), headerTag);

  return headerHtml;
}

function parseLineItem(markdown) {
  if (markdown.startsWith('*')) {
    let startList = list ? "" : "<ul>";

    list = true;
    let innerHtml = wrap(parseText(markdown.substring(2)), 'li');
    innerHtml = startList + innerHtml;

    return innerHtml;
  }
  return null;
}

function parseParagraph(markdown) {
  if (!list) {
    return parseText(markdown);
  } else {
    list = false;
    return `</ul>${parseText(markdown)}`;
  }
}

/**
 * Parse given line of markdown and return it as html
 * 
 * @param {string} markdown Line to parse
 * @returns {string}
 */
function parseLine(markdown) {
  let result = parseHeader(markdown);
  if (result === null) {
    result = parseLineItem(markdown);
  }
  if (result === null) {
    result = parseParagraph(markdown);
  }
  if (result === null) {
    throw new Error('Invalid markdown');
  }
  return result;
}

let list = false;

/**
 * Parses the given markdown text and converts it to html.
 * 
 * @param {string} markdown Markdown text to parse
 * @returns {string}
 */
export function parse(markdown) {
  list = false;
  const lines = markdown.split('\n');
  let result = '';
  for (let i = 0; i < lines.length; i++) {
    let lineResult = parseLine(lines[i]);
    result += lineResult;
  }
  if (list) {
    result += '</ul>';
  }
  
  return result;
}

// MY ACHIVEMENTS
// Refactored the shit out of list
// Removed useless method
// No more methods ending in _ or __! Equality to everyone!
// Cooked some jsdoc (it's tasty now, really)
