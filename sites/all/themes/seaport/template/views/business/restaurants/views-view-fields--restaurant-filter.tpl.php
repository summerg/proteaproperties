<li>
	<a class="btn btn-outline" href="#" data-filter=".<?php print strtolower(preg_replace('/[^a-z0-9.]+/i', '', strip_tags($fields['name']->content))); ?>">
		<?php print $fields['name']->content; ?>
	</a>
</li>