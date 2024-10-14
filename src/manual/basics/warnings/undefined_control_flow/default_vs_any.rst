The old default rule
~~~~~~~~~~~~~~~~~~~~

When the world was young and re2c didn't have the default ``*`` rule (that is,
before re2c-0.13.7) everyone used ``[^]`` as the default rule, as in this
example (any.re):

.. code-block:: cpp

    /*!re2c
        // ... normal rules ...
        [^] { return "any"; }
    */

``[^]`` is just an ordinary rule: it matches any character and has normal
priority (so it should be the last rule). If other rules didn't match, ``[^]``
will match and consume one character.

But exactly what is a *character*? First, an abstract number that is assigned
some sacred meaning within the current encoding — a *code point*. Second, a
minimal piece of information (say, combination of bits) that can represent a
unit of encoded text — a *code unit*. Rules are defined in terms of code points.
Input is measured in code units. In fixed-width encodings (such as ASCII,
EBCDIC, UCS-2, UTF-32, etc.), there is a one-to-one correspondence between code
points and code units. In variable-width encodings (such as UTF-8, UTF-16,
etc.), code points map to code unit sequences of different lengths.

The ``[^]`` rule matches any code point. In fixed-width encodings, it covers all
code units and consumes exactly one of them. In variable-width encodings, it
consumes variable number of code units and may not match some of them. The
example above compiles without warnings with any fixed-width encoding (ASCII by
default). However, with the UTF-8 encoding
```re2c -i8 -Wundefined-control-flow any.re``` complains:

.. code-block:: none

    any.re:4:2: warning: control flow is undefined for strings that match 
            '[\x80-\xC1\xF5-\xFF]'
            '\xF0 [\x0-\x8F\xC0-\xFF]'
            '[\xE1-\xEF] [\x0-\x7F\xC0-\xFF]'
            '\xF4 [\x0-\x7F\x90-\xFF]'
            '\xE0 [\x0-\x9F\xC0-\xFF]'
            '[\xF1-\xF3] [\x0-\x7F\xC0-\xFF]'
            '[\xC2-\xDF] [\x0-\x7F\xC0-\xFF]'
            '\xE0 [\xA0-\xBF] [\x0-\x7F\xC0-\xFF]'
     ... and 7 more, use default rule '*' [-Wundefined-control-flow]

It shows us the patterns that must never appear in valid UTF-8 encoded text. If
the input is not valid UTF-8, lexer behavior is undefined. One would expect that
with UTF-16 (another variable-width encoding), re2c would also report a warning,
but it doesn't. This is because by default, re2c treats Unicode surrogates as
normal code points (for backwards compatibility reasons). If we tell re2c to
exclude surrogates
(```re2c -ix --encoding-policy fail -Wundefined-control-flow```), then we will
get a warning:

.. code-block:: none

    any.re:4:2: warning: control flow is undefined for strings that match 
            '[\xDC00-\xDFFF]'
            '[\xD800-\xDBFF] [\x0-\xDBFF\xE000-\xFFFF]'
    , use default rule '*' [-Wundefined-control-flow]

As you see, it can get quite subtle. A good advice is, always use default rule
``*``: it  matches any code unit regardless of encoding, consumes a single code
unit no matter what and always has the lowest priority. Note that ``*`` is a
built-in hack: it cannot be expressed through ordinary rules.

