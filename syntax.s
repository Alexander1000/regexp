# quantifier rules
quantifier [t:quantifier]
quantifier [t:quantifierOpen t:quantifierNumber t:quantifierClose]
quantifier [t:quantifierOpen t:quantifierNumber t:quantifierDelimiter t:quantifierNumber? t:quantifierClose]

# alphabet rules
alphabet [t:alphabet+]
alphabet [t:alphabetRange+]
alphabetScope [t:squareBracketOpen t:invertAlphabet? s:alphabet+ t:squareBracketClose s:quantifier?]

# match rules
matchQuantified [t:match s:quantifier?]
match [s:matchQuantified+]

# captures
capture [t:captureOpen s:expr t:captureClose s:quantifier?]

# common rules
expr [s:alphabetScope]
expr [s:capture]
