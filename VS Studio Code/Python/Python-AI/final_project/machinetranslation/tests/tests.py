import unittest

from translator import englishToFrench
from translator import frenchToEnglish

def test_englishToFrench():
    assert englishToFrench("Hello") == "Bonjour", "Should be Bonjour"
    assert englishToFrench("") == "", "Should be "

def test_frenchToEnglish():
    assert frenchToEnglish("Bonjour") == "English", "Should be Hello"
    assert frenchToEnglish("") == "", "Should be "



if __name__ == '__main__':
    unittest.main()