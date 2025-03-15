
// Generated from /home/kostya/Projects/simd-translator/grammar/Assembly.g4 by ANTLR 4.13.2


#include "AssemblyListener.h"
#include "AssemblyVisitor.h"

#include "AssemblyParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct AssemblyParserStaticData final {
  AssemblyParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AssemblyParserStaticData(const AssemblyParserStaticData&) = delete;
  AssemblyParserStaticData(AssemblyParserStaticData&&) = delete;
  AssemblyParserStaticData& operator=(const AssemblyParserStaticData&) = delete;
  AssemblyParserStaticData& operator=(AssemblyParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag assemblyParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<AssemblyParserStaticData> assemblyParserStaticData = nullptr;

void assemblyParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (assemblyParserStaticData != nullptr) {
    return;
  }
#else
  assert(assemblyParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AssemblyParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "labelDeclaration", "addStatement", "subStatement", 
      "cmpStatement", "jzStatement", "register", "operand", "label"
    },
    std::vector<std::string>{
      "", "':'", "'add'", "','", "'sub'", "'cmp'", "'jz'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "VALID_NAME", "INT", "NEWLINE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,10,76,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,2,9,7,9,1,0,5,0,22,8,0,10,0,12,0,25,9,0,1,0,5,0,28,8,0,10,
  	0,12,0,31,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,3,1,40,8,1,1,2,1,2,1,2,1,2,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,6,1,6,1,6,1,6,1,7,1,7,1,8,1,8,3,8,72,8,8,1,9,1,9,1,9,0,0,10,0,2,4,
  	6,8,10,12,14,16,18,0,0,72,0,23,1,0,0,0,2,39,1,0,0,0,4,41,1,0,0,0,6,45,
  	1,0,0,0,8,51,1,0,0,0,10,57,1,0,0,0,12,63,1,0,0,0,14,67,1,0,0,0,16,71,
  	1,0,0,0,18,73,1,0,0,0,20,22,3,2,1,0,21,20,1,0,0,0,22,25,1,0,0,0,23,21,
  	1,0,0,0,23,24,1,0,0,0,24,29,1,0,0,0,25,23,1,0,0,0,26,28,5,9,0,0,27,26,
  	1,0,0,0,28,31,1,0,0,0,29,27,1,0,0,0,29,30,1,0,0,0,30,32,1,0,0,0,31,29,
  	1,0,0,0,32,33,5,0,0,1,33,1,1,0,0,0,34,40,3,4,2,0,35,40,3,6,3,0,36,40,
  	3,8,4,0,37,40,3,10,5,0,38,40,3,12,6,0,39,34,1,0,0,0,39,35,1,0,0,0,39,
  	36,1,0,0,0,39,37,1,0,0,0,39,38,1,0,0,0,40,3,1,0,0,0,41,42,3,18,9,0,42,
  	43,5,1,0,0,43,44,5,9,0,0,44,5,1,0,0,0,45,46,5,2,0,0,46,47,3,14,7,0,47,
  	48,5,3,0,0,48,49,3,16,8,0,49,50,5,9,0,0,50,7,1,0,0,0,51,52,5,4,0,0,52,
  	53,3,14,7,0,53,54,5,3,0,0,54,55,3,16,8,0,55,56,5,9,0,0,56,9,1,0,0,0,57,
  	58,5,5,0,0,58,59,3,14,7,0,59,60,5,3,0,0,60,61,3,16,8,0,61,62,5,9,0,0,
  	62,11,1,0,0,0,63,64,5,6,0,0,64,65,3,18,9,0,65,66,5,9,0,0,66,13,1,0,0,
  	0,67,68,5,7,0,0,68,15,1,0,0,0,69,72,3,14,7,0,70,72,5,8,0,0,71,69,1,0,
  	0,0,71,70,1,0,0,0,72,17,1,0,0,0,73,74,5,7,0,0,74,19,1,0,0,0,4,23,29,39,
  	71
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  assemblyParserStaticData = std::move(staticData);
}

}

AssemblyParser::AssemblyParser(TokenStream *input) : AssemblyParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

AssemblyParser::AssemblyParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  AssemblyParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *assemblyParserStaticData->atn, assemblyParserStaticData->decisionToDFA, assemblyParserStaticData->sharedContextCache, options);
}

AssemblyParser::~AssemblyParser() {
  delete _interpreter;
}

const atn::ATN& AssemblyParser::getATN() const {
  return *assemblyParserStaticData->atn;
}

std::string AssemblyParser::getGrammarFileName() const {
  return "Assembly.g4";
}

const std::vector<std::string>& AssemblyParser::getRuleNames() const {
  return assemblyParserStaticData->ruleNames;
}

const dfa::Vocabulary& AssemblyParser::getVocabulary() const {
  return assemblyParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AssemblyParser::getSerializedATN() const {
  return assemblyParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

AssemblyParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssemblyParser::ProgramContext::EOF() {
  return getToken(AssemblyParser::EOF, 0);
}

std::vector<AssemblyParser::StatementContext *> AssemblyParser::ProgramContext::statement() {
  return getRuleContexts<AssemblyParser::StatementContext>();
}

AssemblyParser::StatementContext* AssemblyParser::ProgramContext::statement(size_t i) {
  return getRuleContext<AssemblyParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> AssemblyParser::ProgramContext::NEWLINE() {
  return getTokens(AssemblyParser::NEWLINE);
}

tree::TerminalNode* AssemblyParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(AssemblyParser::NEWLINE, i);
}


size_t AssemblyParser::ProgramContext::getRuleIndex() const {
  return AssemblyParser::RuleProgram;
}

void AssemblyParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AssemblyParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any AssemblyParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::ProgramContext* AssemblyParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AssemblyParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 244) != 0)) {
      setState(20);
      statement();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(29);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AssemblyParser::NEWLINE) {
      setState(26);
      match(AssemblyParser::NEWLINE);
      setState(31);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(32);
    match(AssemblyParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AssemblyParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssemblyParser::LabelDeclarationContext* AssemblyParser::StatementContext::labelDeclaration() {
  return getRuleContext<AssemblyParser::LabelDeclarationContext>(0);
}

AssemblyParser::AddStatementContext* AssemblyParser::StatementContext::addStatement() {
  return getRuleContext<AssemblyParser::AddStatementContext>(0);
}

AssemblyParser::SubStatementContext* AssemblyParser::StatementContext::subStatement() {
  return getRuleContext<AssemblyParser::SubStatementContext>(0);
}

AssemblyParser::CmpStatementContext* AssemblyParser::StatementContext::cmpStatement() {
  return getRuleContext<AssemblyParser::CmpStatementContext>(0);
}

AssemblyParser::JzStatementContext* AssemblyParser::StatementContext::jzStatement() {
  return getRuleContext<AssemblyParser::JzStatementContext>(0);
}


size_t AssemblyParser::StatementContext::getRuleIndex() const {
  return AssemblyParser::RuleStatement;
}

void AssemblyParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void AssemblyParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any AssemblyParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::StatementContext* AssemblyParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, AssemblyParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(39);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssemblyParser::VALID_NAME: {
        enterOuterAlt(_localctx, 1);
        setState(34);
        labelDeclaration();
        break;
      }

      case AssemblyParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(35);
        addStatement();
        break;
      }

      case AssemblyParser::T__3: {
        enterOuterAlt(_localctx, 3);
        setState(36);
        subStatement();
        break;
      }

      case AssemblyParser::T__4: {
        enterOuterAlt(_localctx, 4);
        setState(37);
        cmpStatement();
        break;
      }

      case AssemblyParser::T__5: {
        enterOuterAlt(_localctx, 5);
        setState(38);
        jzStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelDeclarationContext ------------------------------------------------------------------

AssemblyParser::LabelDeclarationContext::LabelDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssemblyParser::LabelContext* AssemblyParser::LabelDeclarationContext::label() {
  return getRuleContext<AssemblyParser::LabelContext>(0);
}

tree::TerminalNode* AssemblyParser::LabelDeclarationContext::NEWLINE() {
  return getToken(AssemblyParser::NEWLINE, 0);
}


size_t AssemblyParser::LabelDeclarationContext::getRuleIndex() const {
  return AssemblyParser::RuleLabelDeclaration;
}

void AssemblyParser::LabelDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabelDeclaration(this);
}

void AssemblyParser::LabelDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabelDeclaration(this);
}


std::any AssemblyParser::LabelDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitLabelDeclaration(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::LabelDeclarationContext* AssemblyParser::labelDeclaration() {
  LabelDeclarationContext *_localctx = _tracker.createInstance<LabelDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, AssemblyParser::RuleLabelDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    label();
    setState(42);
    match(AssemblyParser::T__0);
    setState(43);
    match(AssemblyParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddStatementContext ------------------------------------------------------------------

AssemblyParser::AddStatementContext::AddStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssemblyParser::RegisterContext* AssemblyParser::AddStatementContext::register_() {
  return getRuleContext<AssemblyParser::RegisterContext>(0);
}

AssemblyParser::OperandContext* AssemblyParser::AddStatementContext::operand() {
  return getRuleContext<AssemblyParser::OperandContext>(0);
}

tree::TerminalNode* AssemblyParser::AddStatementContext::NEWLINE() {
  return getToken(AssemblyParser::NEWLINE, 0);
}


size_t AssemblyParser::AddStatementContext::getRuleIndex() const {
  return AssemblyParser::RuleAddStatement;
}

void AssemblyParser::AddStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddStatement(this);
}

void AssemblyParser::AddStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddStatement(this);
}


std::any AssemblyParser::AddStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitAddStatement(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::AddStatementContext* AssemblyParser::addStatement() {
  AddStatementContext *_localctx = _tracker.createInstance<AddStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, AssemblyParser::RuleAddStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    match(AssemblyParser::T__1);
    setState(46);
    register_();
    setState(47);
    match(AssemblyParser::T__2);
    setState(48);
    operand();
    setState(49);
    match(AssemblyParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubStatementContext ------------------------------------------------------------------

AssemblyParser::SubStatementContext::SubStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssemblyParser::RegisterContext* AssemblyParser::SubStatementContext::register_() {
  return getRuleContext<AssemblyParser::RegisterContext>(0);
}

AssemblyParser::OperandContext* AssemblyParser::SubStatementContext::operand() {
  return getRuleContext<AssemblyParser::OperandContext>(0);
}

tree::TerminalNode* AssemblyParser::SubStatementContext::NEWLINE() {
  return getToken(AssemblyParser::NEWLINE, 0);
}


size_t AssemblyParser::SubStatementContext::getRuleIndex() const {
  return AssemblyParser::RuleSubStatement;
}

void AssemblyParser::SubStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStatement(this);
}

void AssemblyParser::SubStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStatement(this);
}


std::any AssemblyParser::SubStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitSubStatement(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::SubStatementContext* AssemblyParser::subStatement() {
  SubStatementContext *_localctx = _tracker.createInstance<SubStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, AssemblyParser::RuleSubStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(AssemblyParser::T__3);
    setState(52);
    register_();
    setState(53);
    match(AssemblyParser::T__2);
    setState(54);
    operand();
    setState(55);
    match(AssemblyParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CmpStatementContext ------------------------------------------------------------------

AssemblyParser::CmpStatementContext::CmpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssemblyParser::RegisterContext* AssemblyParser::CmpStatementContext::register_() {
  return getRuleContext<AssemblyParser::RegisterContext>(0);
}

AssemblyParser::OperandContext* AssemblyParser::CmpStatementContext::operand() {
  return getRuleContext<AssemblyParser::OperandContext>(0);
}

tree::TerminalNode* AssemblyParser::CmpStatementContext::NEWLINE() {
  return getToken(AssemblyParser::NEWLINE, 0);
}


size_t AssemblyParser::CmpStatementContext::getRuleIndex() const {
  return AssemblyParser::RuleCmpStatement;
}

void AssemblyParser::CmpStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCmpStatement(this);
}

void AssemblyParser::CmpStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCmpStatement(this);
}


std::any AssemblyParser::CmpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitCmpStatement(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::CmpStatementContext* AssemblyParser::cmpStatement() {
  CmpStatementContext *_localctx = _tracker.createInstance<CmpStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, AssemblyParser::RuleCmpStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(AssemblyParser::T__4);
    setState(58);
    register_();
    setState(59);
    match(AssemblyParser::T__2);
    setState(60);
    operand();
    setState(61);
    match(AssemblyParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JzStatementContext ------------------------------------------------------------------

AssemblyParser::JzStatementContext::JzStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssemblyParser::LabelContext* AssemblyParser::JzStatementContext::label() {
  return getRuleContext<AssemblyParser::LabelContext>(0);
}

tree::TerminalNode* AssemblyParser::JzStatementContext::NEWLINE() {
  return getToken(AssemblyParser::NEWLINE, 0);
}


size_t AssemblyParser::JzStatementContext::getRuleIndex() const {
  return AssemblyParser::RuleJzStatement;
}

void AssemblyParser::JzStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJzStatement(this);
}

void AssemblyParser::JzStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJzStatement(this);
}


std::any AssemblyParser::JzStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitJzStatement(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::JzStatementContext* AssemblyParser::jzStatement() {
  JzStatementContext *_localctx = _tracker.createInstance<JzStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, AssemblyParser::RuleJzStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(AssemblyParser::T__5);
    setState(64);
    label();
    setState(65);
    match(AssemblyParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegisterContext ------------------------------------------------------------------

AssemblyParser::RegisterContext::RegisterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssemblyParser::RegisterContext::VALID_NAME() {
  return getToken(AssemblyParser::VALID_NAME, 0);
}


size_t AssemblyParser::RegisterContext::getRuleIndex() const {
  return AssemblyParser::RuleRegister;
}

void AssemblyParser::RegisterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegister(this);
}

void AssemblyParser::RegisterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegister(this);
}


std::any AssemblyParser::RegisterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitRegister(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::RegisterContext* AssemblyParser::register_() {
  RegisterContext *_localctx = _tracker.createInstance<RegisterContext>(_ctx, getState());
  enterRule(_localctx, 14, AssemblyParser::RuleRegister);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(AssemblyParser::VALID_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandContext ------------------------------------------------------------------

AssemblyParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssemblyParser::RegisterContext* AssemblyParser::OperandContext::register_() {
  return getRuleContext<AssemblyParser::RegisterContext>(0);
}

tree::TerminalNode* AssemblyParser::OperandContext::INT() {
  return getToken(AssemblyParser::INT, 0);
}


size_t AssemblyParser::OperandContext::getRuleIndex() const {
  return AssemblyParser::RuleOperand;
}

void AssemblyParser::OperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperand(this);
}

void AssemblyParser::OperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperand(this);
}


std::any AssemblyParser::OperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitOperand(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::OperandContext* AssemblyParser::operand() {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState());
  enterRule(_localctx, 16, AssemblyParser::RuleOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssemblyParser::VALID_NAME: {
        setState(69);
        register_();
        break;
      }

      case AssemblyParser::INT: {
        setState(70);
        match(AssemblyParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

AssemblyParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssemblyParser::LabelContext::VALID_NAME() {
  return getToken(AssemblyParser::VALID_NAME, 0);
}


size_t AssemblyParser::LabelContext::getRuleIndex() const {
  return AssemblyParser::RuleLabel;
}

void AssemblyParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void AssemblyParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssemblyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
}


std::any AssemblyParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssemblyVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

AssemblyParser::LabelContext* AssemblyParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 18, AssemblyParser::RuleLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    match(AssemblyParser::VALID_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void AssemblyParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  assemblyParserInitialize();
#else
  ::antlr4::internal::call_once(assemblyParserOnceFlag, assemblyParserInitialize);
#endif
}
