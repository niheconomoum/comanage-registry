<?php
/**
 * COmanage Registry Regex Identifier Validator Plugin Language File
 *
 * Copyright (C) 2016 MLA
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 *
 * @copyright     Copyright (C) 2016 MLA
 * @link          http://www.internet2.edu/comanage COmanage Project
 * @package       registry-plugin
 * @since         COmanage Registry v1.1.0
 * @license       Apache License, Version 2.0 (http://www.apache.org/licenses/LICENSE-2.0)
 * @version       $Id$
 */
  
global $cm_lang, $cm_texts;

// When localizing, the number in format specifications (eg: %1$s) indicates the argument
// position as passed to _txt.  This can be used to process the arguments in
// a different order than they were passed.

$cm_regex_identifier_validator_texts['en_US'] = array(
  // Titles, per-controller
  'ct.regex_identifier_validators.1'  => 'Regular Expression Identifier Validator',
  'ct.regex_identifier_validators.pl' => 'Regular Expression Identifier Validators',
  
  // Error messages
  'er.regexidentifier.error'         => 'preg_match error',
  
  // Plugin texts
  'pl.regexidentifier.pattern'       => 'Pattern',
  'pl.regexidentifier.pattern.desc'  => 'Perl-Compatible Regular Expression that identifier must conform to, eg: <code>/^[[:alnum:]]+$/</code>'
);
