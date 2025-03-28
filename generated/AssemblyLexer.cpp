
// Generated from /home/kostya/Projects/simd-translator/grammar/Assembly.g4 by ANTLR 4.13.2


#include "AssemblyLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct AssemblyLexerStaticData final {
  AssemblyLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AssemblyLexerStaticData(const AssemblyLexerStaticData&) = delete;
  AssemblyLexerStaticData(AssemblyLexerStaticData&&) = delete;
  AssemblyLexerStaticData& operator=(const AssemblyLexerStaticData&) = delete;
  AssemblyLexerStaticData& operator=(AssemblyLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag assemblylexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<AssemblyLexerStaticData> assemblylexerLexerStaticData = nullptr;

void assemblylexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (assemblylexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(assemblylexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AssemblyLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "VALID_NAME", 
      "INT", "NEWLINE", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "':'", "'add'", "','", "'sub'", "'cmp'", "'jz'", "'jmp'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "VALID_NAME", "INT", "NEWLINE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,11,73,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,
  	3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,5,7,
  	49,8,7,10,7,12,7,52,9,7,1,8,3,8,55,8,8,1,8,4,8,58,8,8,11,8,12,8,59,1,
  	9,3,9,63,8,9,1,9,1,9,1,10,4,10,68,8,10,11,10,12,10,69,1,10,1,10,0,0,11,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,1,0,4,3,0,65,90,95,
  	95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,2,0,9,9,32,32,77,0,1,
  	1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,
  	0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,1,23,
  	1,0,0,0,3,25,1,0,0,0,5,29,1,0,0,0,7,31,1,0,0,0,9,35,1,0,0,0,11,39,1,0,
  	0,0,13,42,1,0,0,0,15,46,1,0,0,0,17,54,1,0,0,0,19,62,1,0,0,0,21,67,1,0,
  	0,0,23,24,5,58,0,0,24,2,1,0,0,0,25,26,5,97,0,0,26,27,5,100,0,0,27,28,
  	5,100,0,0,28,4,1,0,0,0,29,30,5,44,0,0,30,6,1,0,0,0,31,32,5,115,0,0,32,
  	33,5,117,0,0,33,34,5,98,0,0,34,8,1,0,0,0,35,36,5,99,0,0,36,37,5,109,0,
  	0,37,38,5,112,0,0,38,10,1,0,0,0,39,40,5,106,0,0,40,41,5,122,0,0,41,12,
  	1,0,0,0,42,43,5,106,0,0,43,44,5,109,0,0,44,45,5,112,0,0,45,14,1,0,0,0,
  	46,50,7,0,0,0,47,49,7,1,0,0,48,47,1,0,0,0,49,52,1,0,0,0,50,48,1,0,0,0,
  	50,51,1,0,0,0,51,16,1,0,0,0,52,50,1,0,0,0,53,55,5,45,0,0,54,53,1,0,0,
  	0,54,55,1,0,0,0,55,57,1,0,0,0,56,58,7,2,0,0,57,56,1,0,0,0,58,59,1,0,0,
  	0,59,57,1,0,0,0,59,60,1,0,0,0,60,18,1,0,0,0,61,63,5,13,0,0,62,61,1,0,
  	0,0,62,63,1,0,0,0,63,64,1,0,0,0,64,65,5,10,0,0,65,20,1,0,0,0,66,68,7,
  	3,0,0,67,66,1,0,0,0,68,69,1,0,0,0,69,67,1,0,0,0,69,70,1,0,0,0,70,71,1,
  	0,0,0,71,72,6,10,0,0,72,22,1,0,0,0,6,0,50,54,59,62,69,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  assemblylexerLexerStaticData = std::move(staticData);
}

}

AssemblyLexer::AssemblyLexer(CharStream *input) : Lexer(input) {
  AssemblyLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *assemblylexerLexerStaticData->atn, assemblylexerLexerStaticData->decisionToDFA, assemblylexerLexerStaticData->sharedContextCache);
}

AssemblyLexer::~AssemblyLexer() {
  delete _interpreter;
}

std::string AssemblyLexer::getGrammarFileName() const {
  return "Assembly.g4";
}

const std::vector<std::string>& AssemblyLexer::getRuleNames() const {
  return assemblylexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& AssemblyLexer::getChannelNames() const {
  return assemblylexerLexerStaticData->channelNames;
}

const std::vector<std::string>& AssemblyLexer::getModeNames() const {
  return assemblylexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& AssemblyLexer::getVocabulary() const {
  return assemblylexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AssemblyLexer::getSerializedATN() const {
  return assemblylexerLexerStaticData->serializedATN;
}

const atn::ATN& AssemblyLexer::getATN() const {
  return *assemblylexerLexerStaticData->atn;
}




void AssemblyLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  assemblylexerLexerInitialize();
#else
  ::antlr4::internal::call_once(assemblylexerLexerOnceFlag, assemblylexerLexerInitialize);
#endif
}
