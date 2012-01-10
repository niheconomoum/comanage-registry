<!--
  /*
   * COmanage Gears CO Person Role Common Fields
   *
   * Version: $Revision$
   * Date: $Date$
   *
   * Copyright (C) 2010-2011 University Corporation for Advanced Internet Development, Inc.
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
   */
-->
<?php
  
  // Globals
  global $cm_lang, $cm_texts;

  // Determine if fields are editable
  $e = false;
  $es = false;

  if(($this->action == "add" && $permissions['add'])
      || ($this->action == "edit" && $permissions['edit']))
    $e = true;

  if($this->action == "edit" && $permissions['editself'])
    $es = true;

  // We shouldn't get here if we don't have at least read permission, but check just in case
  
  if(!$e && !$permissions['view'])
    return(false);

  if($e)
  {
    echo $html->link(_txt('op.back'),
                     array('controller' => 'co_people', 'action' => 'edit', $co_people[0]['CoPerson']['id'], 'co' => $cur_co['Co']['id']),
                     array('class' => 'cancelbutton'));
    
    // This is for beforeFilter
    echo $this->Form->hidden('Co.id', array('default' => $cur_co['Co']['id'])). "\n";
    // And this is to link to the co person
    echo $this->Form->hidden('co_person_id', array('default' => $co_people[0]['CoPerson']['id'])). "\n";
    // Default status is 'Active'
    echo $this->Form->hidden('status', array('default' => 'A')). "\n";
    
    echo '
    <br />
    <br />
    ';
  }
  else
  {
    echo $this->Html->link(_txt('op.back'),
                           array('controller' => 'co_person_roles', 'action' => 'view', $co_people[0]['CoPerson']['id'], 'co' => $cur_co['Co']['id']),
                           array('class' => 'backbutton')) . '
    <br />
    <br />
    ';
  }
  
  // Line number, for rendering
  $l = 1;
?>
<table id="<?php echo $this->action; ?>_co_person_role" class="ui-widget">
  <tbody>
    <?php if($this->action == "compare"): ?>
    <tr>
      <th class="ui-state-default"><?php echo _txt('fd.attribute'); ?></th>
      <th class="ui-state-default"><?php echo Sanitize::html($cur_co['Co']['name']); ?></th>
      <th class="ui-state-default"><?php echo (!empty($org_identities[0]['OrgIdentity']['o']) ? Sanitize::html($org_identities[0]['OrgIdentity']['o']) : _txt('fd.o')); ?></th>
    </tr>
    <?php endif; ?>
    <?php if(!empty($permissions['cous'])): ?>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo Sanitize::html($cur_co['Co']['name']) . " " . _txt('fd.cou'); ?><font class="required">*</font>
      </td>
      <td>
        <?php
          echo (($e && !$es) ? $this->Form->select('cou_id',
                                                   $permissions['cous'],
                                                   (isset($co_person_roles[0]['CoPersonRole']['cou_id'])
                                                    ? $co_person_roles[0]['CoPersonRole']['cou_id']
                                                    : 0),
                                                   array('empty' => false))
                             : Sanitize::html($co_person_roles[0]['Cou']['name']));
        ?>
      </td>
    <?php endif; ?>
    </tr>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo Sanitize::html($cur_co['Co']['name']) . " " . _txt('fd.affiliation'); ?><font class="required">*</font>
      </td>
      <td>
        <?php
          global $cm_lang, $cm_texts;
          
          echo (($e && !$es)? $this->Form->select('affiliation',
                                         $cm_texts[ $cm_lang ]['en.affil'],
                                         (isset($co_person_roles[0]['CoPersonRole']['affiliation'])
                                          ? $co_person_roles[0]['CoPersonRole']['affiliation']
                                          : "M"),
                                         array('empty' => false))
                   : $cm_texts[ $cm_lang ]['en.affil'][ $co_person_roles[0]['CoPersonRole']['affiliation']]);
        ?>
      </td>
    <?php if($this->action == "compare"): ?>
      <td>
        <?php echo $cm_texts[ $cm_lang ]['en.affil'][ $org_identities[0]['OrgIdentity']['affiliation']]; ?>
      </td>
    <?php endif; ?>
    </tr>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo $cur_co['Co']['name'] . " " . _txt('fd.title'); ?>
      </td>
      <td>
        <?php echo (($e && !$es) ? $this->Form->input('title', array('default' => $co_person_roles[0]['CoPersonRole']['title']))
                                 : Sanitize::html($co_person_roles[0]['CoPersonRole']['title'])); ?>
      </td>
    <?php if($this->action == "compare"): ?>
      <td>
        <?php echo Sanitize::html($org_identities[0]['OrgIdentity']['title']); ?>
      </td>
    <?php endif; ?>
    </tr>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo _txt('fd.o'); ?>
      </td>
      <td>
        <?php echo (($e && !$es) ? $this->Form->input('o', array('default' => $cur_co['Co']['name']))
                                 : Sanitize::html($co_person_roles[0]['CoPersonRole']['o'])); ?>
      </td>
    <?php if($this->action == "compare"): ?>
      <td>
        <?php echo Sanitize::html($org_identities[0]['OrgIdentity']['o']); ?>
      </td>
    <?php endif; ?>
    </tr>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo _txt('fd.ou'); ?>
      </td>
      <td>
        <?php echo (($e && !$es) ? $this->Form->input('ou') : Sanitize::html($co_person_roles[0]['CoPersonRole']['ou'])); ?>
      </td>
    <?php if($this->action == "compare"): ?>
      <td>
        <?php echo Sanitize::html($org_identities[0]['OrgIdentity']['ou']); ?>
      </td>
    <?php endif; ?>
    </tr>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo _txt('fd.sponsor') . " ";
              echo _txt('fd.sponsor.desc');
        ?>
      </td>
      <td>
        <?php echo (($e && !$es) ? $this->Form->select('sponsor_co_person_id', $sponsors) : Sanitize::html($sponsors[ $co_person_roles[0]['CoPersonRole']['sponsor_co_person_id'] ])); 
        ?>
      </td>
    <?php if($this->action == "compare"): ?>
      <td>
        <?php echo Sanitize::html($org_identities[0]['OrgIdentity']['sponsor_co_person_id']); ?>
      </td>
    <?php endif; ?>
    </tr>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo _txt('fd.valid.f'); if($e && !$es) echo " " . _txt('fd.valid.f.desc'); ?>
      </td>
      <td>
        <?php echo (($e && !$es)
                    ? $this->Form->text('valid_from', array('class' => 'datepicker-f'))
                    : (($co_person_roles[0]['CoPersonRole']['valid_from'] > 0) ? strftime("%F", strtotime($co_person_roles[0]['CoPersonRole']['valid_from'])) : "")); ?>
      </td>
    </tr>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo _txt('fd.valid.u'); if($e && !$es) echo " " . _txt('fd.valid.u.desc'); ?>
      </td>
      <td>
        <?php echo (($e && !$es)
                    ? $this->Form->text('valid_through', array('class' => 'datepicker-u'))
                    : (($co_person_roles[0]['CoPersonRole']['valid_through'] > 0) ? strftime("%F", strtotime($co_person_roles[0]['CoPersonRole']['valid_through'])) : "")); ?>
      </td>
    </tr>
    <?php if($this->action != "add"): ?>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo _txt('fd.phone'); ?>
      </td>
      <td>
        <?php
          if($e)
          {
            if(isset($co_person_roles[0]['TelephoneNumber']))
            {
              foreach($co_person_roles[0]['TelephoneNumber'] as $t)
              {
                // XXX we already checked for $permissions['edit'], but not ['delete']... should we?
                echo '<a class="deletebutton" title="' . _txt('op.delete') . '" onclick="javascript:js_confirm_delete(\'' . _jtxt(Sanitize::html($t['number'])) . '\', \'' . $html->url(array('controller' => 'telephone_numbers', 'action' => 'delete', $t['id'], 'co' => $cur_co['Co']['id'])) . '\')";>' . _txt('op.delete') . '</a>' . "\n";
                echo $html->link(_txt('op.edit'),
                                 array('controller' => 'telephone_numbers', 'action' => 'edit', $t['id'], 'co' => $cur_co['Co']['id']),
                                 array('class' => 'editbutton')) . "\n";
                echo $html->link($t['number'], array('controller' => 'telephone_numbers', 'action' => 'edit', $t['id'], 'co' => $cur_co['Co']['id']));
                echo " (" . _txt('en.contact', null, $t['type']) . ")<br />\n";
              }
            }
            
            echo $html->link(_txt('op.add'),
                             array('controller' => 'telephone_numbers', 'action' => 'add', 'copersonroleid' => $co_person_roles[0]['CoPersonRole']['id'], 'co' => $cur_co['Co']['id']),
                             array('class' => 'addbutton'));
          }
          else
          {
            if(isset($co_person_roles[0]['TelephoneNumber']))
              foreach($co_person_roles[0]['TelephoneNumber'] as $t)
                echo Sanitize::html($t['number']) . " (" . _txt('en.contact', null, $t['type']) . ")<br />\n";
          }
        ?>
      </td>
    <?php if($this->action == "compare"): ?>
      <td>
        <?php
          if(isset($org_identities[0]['TelephoneNumber']))
            foreach($org_identities[0]['TelephoneNumber'] as $t)
              echo Sanitize::html($t['number']) . " (" . _txt('en.contact', null, $t['type']) . ")<br />\n";
        ?>
      </td>
    <?php endif; ?>
    </tr>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo _txt('fd.address'); ?>
      </td>
      <td>
        <?php
          if($e)
          {
            if(isset($co_person_roles[0]['Address']))
            {
              foreach($co_person_roles[0]['Address'] as $addr)
              {
                // XXX we already checked for $permissions['edit'], but not ['delete']... should we?
                echo '<a class="deletebutton" title="' . _txt('op.delete') . '" onclick="javascript:js_confirm_delete(\'' . _jtxt(Sanitize::html($addr['line1'])) . '\', \'' . $html->url(array('controller' => 'addresses', 'action' => 'delete', $addr['id'], 'co' => $cur_co['Co']['id'])) . '\')";>' . _txt('op.delete') . '</a>' . "\n";
                echo $html->link(_txt('op.edit'),
                                 array('controller' => 'addresses', 'action' => 'edit', $addr['id'], 'co' => $cur_co['Co']['id']),
                                 array('class' => 'editbutton')) . "\n";
                echo $html->link($addr['line1'], array('controller' => 'addresses', 'action' => 'edit', $addr['id'], 'co' => $cur_co['Co']['id']));
                echo " (" . _txt('en.contact', null, $addr['type']) . ")<br />\n";
              }
            }
                
            echo $html->link(_txt('op.add'),
                             array('controller' => 'addresses', 'action' => 'add', 'copersonroleid' => $co_person_roles[0]['CoPersonRole']['id'], 'co' => $cur_co['Co']['id']),
                             array('class' => 'addbutton'));
          }
          else
          {
            if(isset($co_person_roles[0]['Address']))
              foreach($co_person_roles[0]['Address'] as $addr)
                echo Sanitize::html($addr['line1']) . " (" . _txt('en.contact', null, $addr['type']) . ")<br />\n";
          }
        ?>
      </td>
    <?php if($this->action == "compare"): ?>
      <td>
        <?php
          if(isset($org_identities[0]['Address']))
            foreach($org_identities[0]['Address'] as $addr)
              echo Sanitize::html($addr['line1']) . " (" . _txt('en.contact', null, $addr['type']) . ")<br />\n";
        ?>
      </td>
    <?php endif; ?>
    </tr>
    <?php endif; // add ?>
    <?php
      // Check for extended attributes and render
      
      $cl = 'Co' . $cur_co['Co']['id'] . 'PersonExtendedAttribute';
      
      if(!empty($cur_co['CoExtendedAttribute']))
      {
        echo $this->Form->hidden($cl . '.id');
        
        foreach($cur_co['CoExtendedAttribute'] as $c):
    ?>
    <tr class="line<?php echo ($l % 2); $l++; ?>">
      <td>
        <?php echo $c['display_name']; ?>
      </td>
      <td>
        <?php
          $attr = strtolower($c['name']);  
          
          if($c['type'] == 'TIMESTAMP')
          {
            echo ($e && !$es ? $this->Form->text($cl.'.'.$attr, array('class' => 'datepicker'))
                             : (($co_person_roles[0][$cl][$attr] > 0) ? strftime("%F", strtotime($co_person_roles[0][$cl][$attr])) : ""));
          }
          else
          {
            echo ($e && !$es ? $this->Form->input($cl.'.'.$attr,
                                                  isset($co_person_roles[0][$cl][$attr]) ? array('default' => $co_person_roles[0][$cl][$attr]) : array())
                             : Sanitize::html($co_person_roles[0][$cl][$attr]));
          }
        ?>
      </td>
    </tr>
    <?php
        endforeach;
      }
    ?>
    <tr>
      <td>
        <i><font class="required"><?php echo _txt('fd.req'); ?></font></i><br />
      </td>
      <td>
        <?php
          if($e)
            echo $this->Form->submit($submit_label);
        ?>
      </td>
    </tr>
  </tbody>
</table>