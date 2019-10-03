import re

def to_snake(str):
    """ Converts a string to kebab case.
    
    Usage:
        snake('camelCase') -> 'camel_case'
        snake('some text') -> 'some_text'
        snake('some-mixed_string With spaces_underscores-and-hyphens') -> 'some_mixed_string_with_spaces_underscores_and_hyphens'
        snake('AllThe-small Things') -> 'all_the_smal_things'
    """

    return '_'.join(re.sub('([A-Z][a-z]+)', r' \1',
        re.sub('([A-Z]+)', r' \1',
        str.replace('-', ' '))).split()).lower()
