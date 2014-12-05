 #include "ch01/ex1_4.hpp"
 

void encodeSpacesStringNoFindNoInsert(std::string &rhs) {
  std::string::iterator spaceFound = rhs.end();
	for (auto it = rhs.begin(); it != rhs.end(); ++it) {
    if (*it == ' ') {
      if (spaceFound == rhs.end()){
        spaceFound = it;
      }
    }
    else {
      if (spaceFound != rhs.end()) {
        auto spaceEnd = it;
        std::string middleSequence;
        for (auto innerItr = spaceFound; innerItr != spaceEnd; ++innerItr) {
          middleSequence.append("%20");
        }
        auto SequenceBegin = std::distance(rhs.begin(), spaceFound);
        auto SequenceEnd = std::distance(rhs.begin(), spaceEnd);
        std::string sequence(rhs.begin(), rhs.begin() + SequenceBegin);
        sequence.append(middleSequence);
        sequence.append(rhs.begin() + SequenceEnd, rhs.end());
        rhs = sequence;
        it = rhs.begin() + SequenceEnd;
        spaceFound = rhs.end();
      }
    }
	}
  if (spaceFound != rhs.end()){
    rhs.assign(rhs.begin(), spaceFound);
  }
}

void encodeSpacesStringFind(std::string &rhs) {
  std::string::iterator spaceFound = rhs.end();
  std::string::iterator finishSpaces;
  bool changed = false;
  for (auto it = rhs.end()-1; it != rhs.begin(); --it) {
    if (*it == ' ') {
      if (spaceFound == rhs.end()){
        spaceFound = it;
      }
    }
    else {
      finishSpaces = ++it;
      break;
    }
  }
  rhs.assign(rhs.begin(), finishSpaces);
  for (size_t pos = rhs.find(' '); pos != std::string::npos; pos = rhs.find(' ', pos))
  {
    rhs.replace(pos, 1, "%20");
  }
}